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
        arduino->setBaudRate(QSerialPort::Baud38400);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::SoftwareControl);
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
    serialData += arduino->readAll();
    while (serialData.length() >= 29) {
        qDebug() << serialData << "\n";
        while (serialData[0].operator !=(0x44)){
            serialData.remove(0,1);
        }
        serialData.remove(0,1);

        QByteArray serialDataBuffer = serialData.left(29);
        serialData.remove(0,29);
        qDebug() << serialDataBuffer << "\n";
        serialBuffer = QString::fromStdString(serialDataBuffer.toStdString());
        QStringList buffer_Split = serialBuffer.split(",");
        if (buffer_Split.length() == 5) {
        Dialog::updateInterface(buffer_Split);
        }

    }
    arduino->clear();
    //QStringList buffer_split = serialBuffer.split(","); //  split the serialBuffer string, parsing with ',' as the separator
    /*
    if (arduino->canReadLine()){
        serialData = arduino->readLine();
        serialData = serialData.trimmed();
        serialBuffer = QString::fromStdString(serialData.toStdString());
        serialBuffer = QString::fromStdString(serialData.toStdString());
        qDebug() << buffer_split << "\n";
        if(buffer_split.length() == 5) {
        Dialog::updateInterface(buffer_split);
        if (recordingState) {
        Dialog::writeCSV(buffer_split);
        }
    }

        //serialBuffer = "";
        serialData.clear();
    }
*/

}

void Dialog::updateInterface(QStringList sensor_readings)
{
    //update the value displayed on the lcdNumber

    float sensorNumber1 = sensor_readings[1].toFloat() * 5 / 1024 * 124.724 - 58.461;
    float sensorNumber2 = sensor_readings[2].toFloat() * 5 / 1024;
    float sensorNumber3 = sensor_readings[3].toFloat() * 5 / 1024 * 124.724 - 58.461;
    float sensorNumber4 = sensor_readings[4].toFloat() * 5 / 1024;

    QString outputString1 = QString::number(sensorNumber1, 'f', 2);
    QString outputString2 = QString::number(sensorNumber2, 'f', 2);
    QString outputString3 = QString::number(sensorNumber3, 'f', 2);
    QString outputString4 = QString::number(sensorNumber4, 'f', 2);

    ui->pressure1_display->display(outputString1);
    ui->pressure2_display->display(outputString2);
    ui->pressure3_display->display(outputString3);
    ui->pressure4_display->display(outputString4);

    if (recordingState) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly| QIODevice::Append)){
            QTextStream stream(&file);
            stream << sensor_readings[0] << "," << outputString1 <<"," << outputString2 << "," << outputString3 << "," << outputString4 << "\n";
        }
    }
}


void Dialog::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat() == false){
        switch(event->key()) {
        case Qt::Key_A: //Engine Purge Open
            arduino->write("A");
            ui->EnginePurgeState->setText("OPEN");
            break;
        case Qt::Key_Z: //Engine Purge Close
            arduino->write("Z");
            ui->EnginePurgeState->setText("CLOSED");
            break;
        case Qt::Key_S: //LOX Press Open
            arduino->write("S");
            ui->LOXPressState->setText("OPEN");
            break;
        case Qt::Key_X: //LOX Press Close
            arduino->write("X");
            ui->LOXPressState->setText("CLOSED");
            break;
        case Qt::Key_D: //LOX Vent Open
            arduino->write("D");
            ui->LOXVentState->setText("OPEN");
            break;
        case Qt::Key_C: //LOX Vent Close
            arduino->write("C");
            ui->LOXVentState->setText("CLOSED");
            break;
        case Qt::Key_F: //Injector Chill Open
            if (!propFlowInhibit)
            {
                arduino->write("F");
                ui->InjectorChillState->setText("OPEN");
            }
            break;
        case Qt::Key_V: //Injector Chill Close
            arduino->write("V");
            if (!propFlowInhibit) {
                ui->InjectorChillState->setText("CLOSED");
            }
            break;
        case Qt::Key_G:
            if (!propFlowInhibit) //LOX Main Open
            {
                arduino->write("G");
                ui->LOXMainState->setText("OPEN");
            }
            break;
        case Qt::Key_B: //LOX Main Close
            arduino->write("B");
            if (!propFlowInhibit) {
                ui->LOXMainState->setText("CLOSED");
            }
            break;
        case Qt::Key_H: //Fuel Press Open
            arduino->write("H");
            ui->FuelPressState->setText("OPEN");
            break;
        case Qt::Key_N: //Fuel Press Close
            arduino->write("N");
            ui->FuelPressState->setText("CLOSED");
            break;
        case Qt::Key_J: //Fuel Pre-Stage Open
            if (!propFlowInhibit)
            {
                arduino->write("J");
                ui->FuelPreState->setText("OPEN");
            }
            break;
        case Qt::Key_M: //Fuel Pre-Stage Close
                arduino->write("M");
            if (!propFlowInhibit) {
                ui->FuelPreState->setText("CLOSED");
            }
            break;
        case Qt::Key_K:
            if(!propFlowInhibit) //Fuel Main Open
            {
                arduino->write("K");
                ui->FuelMainState->setText("OPEN");
            }
            break;
        case Qt::Key_Comma: //Fuel Main Close
            arduino->write(",");
            if (!propFlowInhibit) {
                ui->FuelMainState->setText("CLOSED");
            }
            break;
        case Qt::Key_8: //Prop Inhibit On
            arduino->write("8");
            propFlowInhibit = true;
            ui->FuelPreState->setText("INHIBIT");
            ui->LOXMainState->setText("INHIBIT");
            ui->InjectorChillState->setText("INHIBIT");
            ui->FuelMainState->setText("INHIBIT");
            break;
        case Qt::Key_9: //Prop Inhibit Off
            arduino->write("9");
            propFlowInhibit = false;

            ui->FuelPreState->setText("CLOSED");
            ui->LOXMainState->setText("CLOSED");
            ui->InjectorChillState->setText("CLOSED");
            ui->FuelMainState->setText("CLOSED");
            break;
        case Qt::Key_Minus: //PreStage
            arduino->write("-");
            break;
        case Qt::Key_Equal: //Main Stage
            arduino->write("=");
            break;
        case Qt::Key_Backslash: //Shutdown
            arduino->write("[");
            break;
        case Qt::Key_BracketRight: //Purge
            arduino->write("]");
            break;
        case Qt::Key_R: //Toggle data collection
            recordingState = !recordingState;
            if (recordingState) {
                arduino->write("R");
                ui->recordingLabel->setText("RECORDING: ON");
                QString nameString = QDateTime::currentDateTime().toString("MM.dd.yyyy.hh.mm.ss");
                fileName = "Data." + nameString + ".csv";
                qDebug() << fileName << "\n";
                QFile file(fileName);
                if (file.open(QIODevice::WriteOnly| QIODevice::Append)){
                    QTextStream stream(&file);
                    stream << "Time (ms),P1(psi),P2(psi),P3(psi),P4(psi),T1,T2\n\n";
                }
            }
            else {
                ui->recordingLabel->setText("RECORDING: OFF");
            }
            break;
        default:break;
        }
        arduino->waitForBytesWritten(100);
    }
}
