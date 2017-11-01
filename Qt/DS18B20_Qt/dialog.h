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

private:
    Ui::Dialog *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 1027;
    static const quint16 arduino_uno_product_id = 24577;
    bool propFlowInhibit = true;
    bool recordingState = false;
    QByteArray serialData;
    QString serialBuffer;
    QStringList parsed_data;
    QString fileName;
    double temperature_value;
};

#endif // DIALOG_H
