#include "dialog.h"
#include "ui_dialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QCoreApplication>
#include <string>
#include <QDebug>
#include <QMessageBox>
#include <QKeyEvent>
#include <QDateTime>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->temp1_display->display("-------");
    ui->temp2_display->display("-------");
    ui->FuelPreState->setText("INHIBIT");
    ui->LOXMainState->setText("INHIBIT");
    ui->InjectorChillState->setText("INHIBIT");
    ui->FuelMainState->setText("INHIBIT");
    arduino = new QSerialPort(this);
    serialBuffer = "";
    //parsed_data = "";
    temperature_value = 0.0;

    QString current = QDateTime::currentDateTime().toString();

    QFile file("dataOutput.csv");
    if (file.open(QIODevice::WriteOnly| QIODevice::Append)){
        QTextStream stream(&file);
        stream << "DATA CAPTURED " << current << "\n";
        stream << "Time (ms),P1(0-1024),P2(0-1024),P3(0-1024),P4(0-1024),T1,T2\n";
    }
     //  Testing code, prints the description, vendor id, and product id of all ports.
     //*//  Used it to determine the values for the arduino uno.
     //*
     //*
    qDebug() << "Number of ports: " << QSerialPortInfo::availablePorts().length() << "\n";
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Description: " << serialPortInfo.description() << "\n";
        qDebug() << "Has vendor id?: " << serialPortInfo.hasVendorIdentifier() << "\n";
        qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier() << "\n";
        qDebug() << "Has product id?: " << serialPortInfo.hasProductIdentifier() << "\n";
        qDebug() << "Product ID: " << serialPortInfo.productIdentifier() << "\n";
    }



    /*
     *   Identify the port the arduino uno is on.
     */
    bool arduino_is_available = false;
    QString arduino_uno_port_name;
    //
    //  For each available serial port
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        //  check if the serialport has both a product identifier and a vendor identifier
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            //  check if the product ID and the vendor ID match those of the arduino uno
            if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                    && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                arduino_is_available = true; //    arduino uno is available on this port
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }

    /*
     *  Open and configure the arduino port if available
     */
    if(arduino_is_available){
        qDebug() << "Found the arduino port...\n";
        arduino->setPortName(arduino_uno_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud115200);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    }else{
        qDebug() << "Couldn't find the correct port for the arduino.\n";
        QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
    }
}

Dialog::~Dialog()
{
    if(arduino->isOpen()){
        arduino->close(); //    Close the serial port if it's open.
    }
    delete ui;
}

void Dialog::readSerial()
{
    /*
     * readyRead() doesn't guarantee that the entire message will be received all at once.
     * The message can arrive split into parts.  Need to buffer the serial data and then parse for the temperature value.
     *
     */
    QStringList buffer_split = serialBuffer.split(","); //  split the serialBuffer string, parsing with ',' as the separator
    if (arduino->canReadLine()){
        serialData = arduino->readLine();
        serialData = serialData.trimmed();
        serialBuffer = QString::fromStdString(serialData.toStdString());
        buffer_split = serialBuffer.split(",");
        qDebug() << buffer_split << "\n";
        if(buffer_split.length() == 7) {
        Dialog::updateInterface(buffer_split);
        Dialog::writeCSV(buffer_split);
    }

        //serialBuffer = "";
        serialData.clear();
    }

}

void Dialog::updateInterface(QStringList sensor_readings)
{
    //update the value displayed on the lcdNumber
    ui->pressure1_display->display(sensor_readings[1]);
   ui->pressure2_display->display(sensor_readings[2]);
    ui->pressure3_display->display(sensor_readings[3]);
    ui->pressure4_display->display(sensor_readings[4]);
    ui->temp1_display->display(sensor_readings[5]);
    ui->temp2_display->display(sensor_readings[6]);

}

void Dialog::writeCSV(QStringList data)
{
    QFile file("dataOutput.csv");
    if (file.open(QIODevice::WriteOnly| QIODevice::Append)){
        QTextStream stream(&file);
        stream << data[0] << "," << data[1] <<"," << data[2] << "," << data[3] << "," << data[4] << "," << data[5] << "," <<data[6]<< "\n";
    }
}

void Dialog::keyReleaseEvent(QKeyEvent *event)
{
   if(event->key() == Qt::Key_A) //Engine Purge Open
   {
       arduino->write("A");
       ui->EnginePurgeState->setText("OPEN");
   }
   else if(event->key() == Qt::Key_Z) //Engine Purge Close
   {
       arduino->write("Z");
       ui->EnginePurgeState->setText("CLOSED");
   }
   else if(event->key() == Qt::Key_S) //LOX Press Open
   {
       arduino->write("S");
       ui->LOXPressState->setText("OPEN");
   }
   else if(event->key() == Qt::Key_X) //LOX Press Close
   {
       arduino->write("X");
       ui->LOXPressState->setText("CLOSED");
   }
   else if(event->key() == Qt::Key_D) //LOX Vent Open
   {
       arduino->write("D");
       ui->LOXVentState->setText("OPEN");
   }
   else if(event->key() == Qt::Key_C) //LOX Vent Close
   {
       arduino->write("C");
       ui->LOXVentState->setText("CLOSED");
   }
   else if(event->key() == Qt::Key_F && !propFlowInhibit) //Injector Chill Open
   {
       arduino->write("F");
       ui->InjectorChillState->setText("OPEN");
   }
   else if(event->key() == Qt::Key_V) //Injector Chill Close
   {
       arduino->write("V");
       if (!propFlowInhibit) {
       ui->InjectorChillState->setText("CLOSED");
       }
   }
   else if(event->key() == Qt::Key_G && !propFlowInhibit) //LOX Main Open
   {
       arduino->write("G");
       ui->LOXMainState->setText("OPEN");
   }
   else if(event->key() == Qt::Key_B) //LOX Main Close
   {
       arduino->write("B");
       if (!propFlowInhibit) {
       ui->LOXMainState->setText("CLOSED");
       }
   }
   else if(event->key() == Qt::Key_H) //Fuel Press Open
   {
       arduino->write("H");
       ui->FuelPressState->setText("OPEN");
   }
   else if(event->key() == Qt::Key_N) //Fuel Press Close
   {
       arduino->write("N");
       ui->FuelPressState->setText("CLOSED");
   }
   else if(event->key() == Qt::Key_J && !propFlowInhibit) //Fuel Pre-Stage Open
   {
       arduino->write("J");
       ui->FuelPreState->setText("OPEN");
   }
   else if(event->key() == Qt::Key_M) //Fuel Pre-Stage Close
   {
       arduino->write("M");
       if (!propFlowInhibit) {
       ui->FuelPreState->setText("CLOSED");
       }
   }
   else if(event->key() == Qt::Key_K && !propFlowInhibit) //Fuel Main Open
   {
       arduino->write("K");
       ui->FuelMainState->setText("OPEN");
   }
   else if(event->key() == Qt::Key_Comma) //Fuel Main Close
   {
       arduino->write(",");
       if (!propFlowInhibit) {
       ui->FuelMainState->setText("CLOSED");
       }
   }
   else if(event->key() == Qt::Key_8) //Prop Inhibit On
   {
       arduino->write("8");
       propFlowInhibit = true;
       arduino->write(",");
       ui->FuelPreState->setText("INHIBIT");
       arduino->write("M");
       ui->LOXMainState->setText("INHIBIT");
       arduino->write("B");
       ui->InjectorChillState->setText("INHIBIT");
       arduino->write("V");
       ui->FuelMainState->setText("INHIBIT");

   }
   else if(event->key() == Qt::Key_9) //Prop Inhibit Off
   {
       arduino->write("9");
       propFlowInhibit = false;

       ui->FuelPreState->setText("CLOSED");
       ui->LOXMainState->setText("CLOSED");
       ui->InjectorChillState->setText("CLOSED");
       ui->FuelMainState->setText("CLOSED");
   }
   else if(event->key() == Qt::Key_Minus) //PreStage
   {
       arduino->write("-");
   }
   else if(event->key() == Qt::Key_Equal) //Main Stage
   {
       arduino->write("=");
   }
   else if(event->key() == Qt::Key_Backslash) //Shutdown
   {
       arduino->write("[");
   }
   else if(event->key() == Qt::Key_BracketRight) //Purge
   {
       arduino->write("]");
   }
}
