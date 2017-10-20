#include "dialog.h"
#include "ui_dialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QCoreApplication>
#include <string>
#include <QDebug>
#include <QMessageBox>
#include <QKeyEvent>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->temp_lcdNumber->display("-------");
    arduino = new QSerialPort(this);
    serialBuffer = "";
    parsed_data = "";
    temperature_value = 0.0;

    /*
     *  Testing code, prints the description, vendor id, and product id of all ports.
     *  Used it to determine the values for the arduino uno.
     *
     *
    qDebug() << "Number of ports: " << QSerialPortInfo::availablePorts().length() << "\n";
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Description: " << serialPortInfo.description() << "\n";
        qDebug() << "Has vendor id?: " << serialPortInfo.hasVendorIdentifier() << "\n";
        qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier() << "\n";
        qDebug() << "Has product id?: " << serialPortInfo.hasProductIdentifier() << "\n";
        qDebug() << "Product ID: " << serialPortInfo.productIdentifier() << "\n";
    }
    */


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

    //  Check to see if there less than 3 tokens in buffer_split.
    //  If there are at least 3 then this means there were 2 commas,
    //  means there is a parsed temperature value as the second token (between 2 commas)
    if(buffer_split.length() < 3){
        // no parsed value yet so continue accumulating bytes from serial in the buffer.
        serialData = arduino->readAll();
        serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
        serialData.clear();
    }else{
        // the second element of buffer_split is parsed correctly, update the temperature value on temp_lcdNumber
        serialBuffer = "";
        qDebug() << buffer_split << "\n";
        parsed_data = buffer_split[1];
        temperature_value = parsed_data.toDouble(); // convert to fahrenheit
        qDebug() << "Temperature: " << temperature_value << "\n";
        parsed_data = QString::number(temperature_value, 'g', 4); // format precision of temperature_value to 4 digits or fewer
        Dialog::updateTemperature(parsed_data);
    }

}

void Dialog::updateTemperature(QString sensor_reading)
{
    //  update the value displayed on the lcdNumber
    ui->temp_lcdNumber->display(sensor_reading);
}

void Dialog::keyReleaseEvent(QKeyEvent *event)
{
   if(event->key() == Qt::Key_A) //Engine Purge Open
   {
       arduino->write("A");
       ui->EnginePurgeState->setText("OPEN");
   }
   if(event->key() == Qt::Key_Z) //Engine Purge Close
   {
       arduino->write("Z");
       ui->EnginePurgeState->setText("CLOSED");
   }
   if(event->key() == Qt::Key_S) //LOX Press Open
   {
       arduino->write("S");
       ui->LOXPressState->setText("OPEN");
   }
   if(event->key() == Qt::Key_X) //LOX Press Close
   {
       arduino->write("X");
       ui->LOXPressState->setText("CLOSED");
   }
   if(event->key() == Qt::Key_D) //LOX Vent Open
   {
       arduino->write("D");
   }
   if(event->key() == Qt::Key_C) //LOX Vent Close
   {
       arduino->write("C");
   }
   if(event->key() == Qt::Key_F) //Injector Chill Open
   {
       arduino->write("F");
   }
   if(event->key() == Qt::Key_V) //Injector Chill Close
   {
       arduino->write("V");
   }
   if(event->key() == Qt::Key_G) //LOX Main Open
   {
       arduino->write("G");
   }
   if(event->key() == Qt::Key_B) //LOX Main Close
   {
       arduino->write("B");
   }
   if(event->key() == Qt::Key_H) //Fuel Press Open
   {
       arduino->write("H");
   }
   if(event->key() == Qt::Key_N) //Fuel Press Close
   {
       arduino->write("N");
   }
   if(event->key() == Qt::Key_J) //Fuel Pre-Stage Open
   {
       arduino->write("J");
   }
   if(event->key() == Qt::Key_M) //Fuel Pre-Stage Close
   {
       arduino->write("M");
   }
   if(event->key() == Qt::Key_K) //Fuel Main Open
   {
       arduino->write("K");
   }
   if(event->key() == Qt::Key_Comma) //Fuel Main Close
   {
       arduino->write(",");
   }
   if(event->key() == Qt::Key_8) //Prop Inhibit On
   {
       arduino->write("8");
   }
   if(event->key() == Qt::Key_9) //Prop
   {
       arduino->write("9");
   }
   if(event->key() == Qt::Key_Minus)
   {
       arduino->write("-");
   }
   if(event->key() == Qt::Key_Equal)
   {
       arduino->write("=");
   }
   if(event->key() == Qt::Key_Backspace)
   {
       arduino->write("[");
   }
   if(event->key() == Qt::Key_Backslash)
   {
       arduino->write("]");
   }
}
