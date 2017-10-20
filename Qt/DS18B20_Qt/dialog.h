#ifndef DIALOG_H
#define DIALOG_H

#include <QKeyEvent>
#include <QDialog>
#include <QSerialPort>
#include <QByteArray>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void keyReleaseEvent(QKeyEvent *);
    void readSerial();
    void updateInterface(QStringList);
    void writeCSV(QByteArray sensor_readings);

private:
    Ui::Dialog *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QByteArray serialData;
    QString serialBuffer;
    QStringList parsed_data;
    double temperature_value;
};

#endif // DIALOG_H
