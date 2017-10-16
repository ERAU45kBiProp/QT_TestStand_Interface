/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *SolenoidStates;
    QLabel *StateTitle;
    QHBoxLayout *EnginePurge;
    QLabel *EnginePurgeLabel;
    QLabel *EnginePurgeState;
    QHBoxLayout *LOXPress;
    QLabel *LOXPressLabel;
    QLabel *LOXPressState;
    QHBoxLayout *LOXVent;
    QLabel *LOXVentLabel;
    QLabel *LOXVentState;
    QHBoxLayout *InjectorChill;
    QLabel *InjectorChillLabel;
    QLabel *InjectorChillState;
    QHBoxLayout *LOXMain;
    QLabel *LOXMainLabel;
    QLabel *LOXMainState;
    QHBoxLayout *FuelPress;
    QLabel *FuelPressLabel;
    QLabel *FuelPressState;
    QHBoxLayout *FuelPre;
    QLabel *FuelPreLabel;
    QLabel *FuelPreState;
    QHBoxLayout *FuelMain;
    QLabel *FuelMainLabel;
    QLabel *FuelMainState;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *Thermocouple1;
    QLabel *temp_label;
    QLCDNumber *temp_lcdNumber;
    QHBoxLayout *Thermocouple2;
    QLabel *temp_label_2;
    QLCDNumber *temp_lcdNumber_2;
    QHBoxLayout *OxTankPressure;
    QLabel *temp_label_3;
    QLCDNumber *temp_lcdNumber_3;
    QHBoxLayout *FuelTankPressure;
    QLabel *temp_label_4;
    QLCDNumber *temp_lcdNumber_4;
    QHBoxLayout *OxPressure;
    QLabel *temp_label_6;
    QLCDNumber *temp_lcdNumber_6;
    QHBoxLayout *FuelPressure;
    QLabel *temp_label_5;
    QLCDNumber *temp_lcdNumber_5;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(800, 600);
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(590, 140, 211, 461));
        SolenoidStates = new QVBoxLayout(verticalLayoutWidget);
        SolenoidStates->setSpacing(6);
        SolenoidStates->setContentsMargins(11, 11, 11, 11);
        SolenoidStates->setObjectName(QStringLiteral("SolenoidStates"));
        SolenoidStates->setContentsMargins(0, 0, 0, 0);
        StateTitle = new QLabel(verticalLayoutWidget);
        StateTitle->setObjectName(QStringLiteral("StateTitle"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        StateTitle->setFont(font);
        StateTitle->setAlignment(Qt::AlignCenter);

        SolenoidStates->addWidget(StateTitle);

        EnginePurge = new QHBoxLayout();
        EnginePurge->setSpacing(6);
        EnginePurge->setObjectName(QStringLiteral("EnginePurge"));
        EnginePurgeLabel = new QLabel(verticalLayoutWidget);
        EnginePurgeLabel->setObjectName(QStringLiteral("EnginePurgeLabel"));
        QFont font1;
        font1.setPointSize(12);
        EnginePurgeLabel->setFont(font1);
        EnginePurgeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        EnginePurge->addWidget(EnginePurgeLabel);

        EnginePurgeState = new QLabel(verticalLayoutWidget);
        EnginePurgeState->setObjectName(QStringLiteral("EnginePurgeState"));
        EnginePurgeState->setEnabled(true);
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        EnginePurgeState->setFont(font2);
        EnginePurgeState->setFrameShape(QFrame::Box);
        EnginePurgeState->setFrameShadow(QFrame::Raised);
        EnginePurgeState->setAlignment(Qt::AlignCenter);

        EnginePurge->addWidget(EnginePurgeState);


        SolenoidStates->addLayout(EnginePurge);

        LOXPress = new QHBoxLayout();
        LOXPress->setSpacing(6);
        LOXPress->setObjectName(QStringLiteral("LOXPress"));
        LOXPressLabel = new QLabel(verticalLayoutWidget);
        LOXPressLabel->setObjectName(QStringLiteral("LOXPressLabel"));
        LOXPressLabel->setFont(font1);
        LOXPressLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        LOXPress->addWidget(LOXPressLabel);

        LOXPressState = new QLabel(verticalLayoutWidget);
        LOXPressState->setObjectName(QStringLiteral("LOXPressState"));
        LOXPressState->setFont(font2);
        LOXPressState->setFrameShape(QFrame::Box);
        LOXPressState->setFrameShadow(QFrame::Raised);
        LOXPressState->setAlignment(Qt::AlignCenter);

        LOXPress->addWidget(LOXPressState);


        SolenoidStates->addLayout(LOXPress);

        LOXVent = new QHBoxLayout();
        LOXVent->setSpacing(6);
        LOXVent->setObjectName(QStringLiteral("LOXVent"));
        LOXVentLabel = new QLabel(verticalLayoutWidget);
        LOXVentLabel->setObjectName(QStringLiteral("LOXVentLabel"));
        LOXVentLabel->setFont(font1);
        LOXVentLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        LOXVent->addWidget(LOXVentLabel);

        LOXVentState = new QLabel(verticalLayoutWidget);
        LOXVentState->setObjectName(QStringLiteral("LOXVentState"));
        LOXVentState->setFont(font2);
        LOXVentState->setFrameShape(QFrame::Box);
        LOXVentState->setFrameShadow(QFrame::Raised);
        LOXVentState->setAlignment(Qt::AlignCenter);

        LOXVent->addWidget(LOXVentState);


        SolenoidStates->addLayout(LOXVent);

        InjectorChill = new QHBoxLayout();
        InjectorChill->setSpacing(6);
        InjectorChill->setObjectName(QStringLiteral("InjectorChill"));
        InjectorChillLabel = new QLabel(verticalLayoutWidget);
        InjectorChillLabel->setObjectName(QStringLiteral("InjectorChillLabel"));
        InjectorChillLabel->setFont(font1);
        InjectorChillLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        InjectorChill->addWidget(InjectorChillLabel);

        InjectorChillState = new QLabel(verticalLayoutWidget);
        InjectorChillState->setObjectName(QStringLiteral("InjectorChillState"));
        InjectorChillState->setFont(font2);
        InjectorChillState->setFrameShape(QFrame::Box);
        InjectorChillState->setFrameShadow(QFrame::Raised);
        InjectorChillState->setAlignment(Qt::AlignCenter);

        InjectorChill->addWidget(InjectorChillState);


        SolenoidStates->addLayout(InjectorChill);

        LOXMain = new QHBoxLayout();
        LOXMain->setSpacing(6);
        LOXMain->setObjectName(QStringLiteral("LOXMain"));
        LOXMainLabel = new QLabel(verticalLayoutWidget);
        LOXMainLabel->setObjectName(QStringLiteral("LOXMainLabel"));
        LOXMainLabel->setFont(font1);
        LOXMainLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        LOXMain->addWidget(LOXMainLabel);

        LOXMainState = new QLabel(verticalLayoutWidget);
        LOXMainState->setObjectName(QStringLiteral("LOXMainState"));
        LOXMainState->setFont(font2);
        LOXMainState->setFrameShape(QFrame::Box);
        LOXMainState->setFrameShadow(QFrame::Raised);
        LOXMainState->setAlignment(Qt::AlignCenter);

        LOXMain->addWidget(LOXMainState);


        SolenoidStates->addLayout(LOXMain);

        FuelPress = new QHBoxLayout();
        FuelPress->setSpacing(6);
        FuelPress->setObjectName(QStringLiteral("FuelPress"));
        FuelPressLabel = new QLabel(verticalLayoutWidget);
        FuelPressLabel->setObjectName(QStringLiteral("FuelPressLabel"));
        FuelPressLabel->setFont(font1);
        FuelPressLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        FuelPress->addWidget(FuelPressLabel);

        FuelPressState = new QLabel(verticalLayoutWidget);
        FuelPressState->setObjectName(QStringLiteral("FuelPressState"));
        FuelPressState->setFont(font2);
        FuelPressState->setFrameShape(QFrame::Box);
        FuelPressState->setFrameShadow(QFrame::Raised);
        FuelPressState->setAlignment(Qt::AlignCenter);

        FuelPress->addWidget(FuelPressState);


        SolenoidStates->addLayout(FuelPress);

        FuelPre = new QHBoxLayout();
        FuelPre->setSpacing(6);
        FuelPre->setObjectName(QStringLiteral("FuelPre"));
        FuelPreLabel = new QLabel(verticalLayoutWidget);
        FuelPreLabel->setObjectName(QStringLiteral("FuelPreLabel"));
        FuelPreLabel->setFont(font1);
        FuelPreLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        FuelPre->addWidget(FuelPreLabel);

        FuelPreState = new QLabel(verticalLayoutWidget);
        FuelPreState->setObjectName(QStringLiteral("FuelPreState"));
        FuelPreState->setFont(font2);
        FuelPreState->setFrameShape(QFrame::Box);
        FuelPreState->setFrameShadow(QFrame::Raised);
        FuelPreState->setAlignment(Qt::AlignCenter);

        FuelPre->addWidget(FuelPreState);


        SolenoidStates->addLayout(FuelPre);

        FuelMain = new QHBoxLayout();
        FuelMain->setSpacing(6);
        FuelMain->setObjectName(QStringLiteral("FuelMain"));
        FuelMainLabel = new QLabel(verticalLayoutWidget);
        FuelMainLabel->setObjectName(QStringLiteral("FuelMainLabel"));
        FuelMainLabel->setFont(font1);
        FuelMainLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        FuelMain->addWidget(FuelMainLabel);

        FuelMainState = new QLabel(verticalLayoutWidget);
        FuelMainState->setObjectName(QStringLiteral("FuelMainState"));
        FuelMainState->setFont(font2);
        FuelMainState->setFrameShape(QFrame::Box);
        FuelMainState->setFrameShadow(QFrame::Raised);
        FuelMainState->setAlignment(Qt::AlignCenter);

        FuelMain->addWidget(FuelMainState);


        SolenoidStates->addLayout(FuelMain);

        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 401, 571));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Thermocouple1 = new QHBoxLayout();
        Thermocouple1->setSpacing(6);
        Thermocouple1->setObjectName(QStringLiteral("Thermocouple1"));
        temp_label = new QLabel(layoutWidget);
        temp_label->setObjectName(QStringLiteral("temp_label"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        temp_label->setFont(font3);
        temp_label->setAlignment(Qt::AlignCenter);

        Thermocouple1->addWidget(temp_label);

        temp_lcdNumber = new QLCDNumber(layoutWidget);
        temp_lcdNumber->setObjectName(QStringLiteral("temp_lcdNumber"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 94, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush);
        QBrush brush2(QColor(60, 60, 60, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush2);
        QBrush brush3(QColor(76, 76, 76, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        temp_lcdNumber->setPalette(palette);
        temp_lcdNumber->setDigitCount(7);

        Thermocouple1->addWidget(temp_lcdNumber);


        verticalLayout->addLayout(Thermocouple1);

        Thermocouple2 = new QHBoxLayout();
        Thermocouple2->setSpacing(6);
        Thermocouple2->setObjectName(QStringLiteral("Thermocouple2"));
        temp_label_2 = new QLabel(layoutWidget);
        temp_label_2->setObjectName(QStringLiteral("temp_label_2"));
        temp_label_2->setFont(font3);
        temp_label_2->setAlignment(Qt::AlignCenter);

        Thermocouple2->addWidget(temp_label_2);

        temp_lcdNumber_2 = new QLCDNumber(layoutWidget);
        temp_lcdNumber_2->setObjectName(QStringLiteral("temp_lcdNumber_2"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        temp_lcdNumber_2->setPalette(palette1);
        temp_lcdNumber_2->setDigitCount(7);

        Thermocouple2->addWidget(temp_lcdNumber_2);


        verticalLayout->addLayout(Thermocouple2);

        OxTankPressure = new QHBoxLayout();
        OxTankPressure->setSpacing(6);
        OxTankPressure->setObjectName(QStringLiteral("OxTankPressure"));
        temp_label_3 = new QLabel(layoutWidget);
        temp_label_3->setObjectName(QStringLiteral("temp_label_3"));
        temp_label_3->setFont(font3);
        temp_label_3->setAlignment(Qt::AlignCenter);

        OxTankPressure->addWidget(temp_label_3);

        temp_lcdNumber_3 = new QLCDNumber(layoutWidget);
        temp_lcdNumber_3->setObjectName(QStringLiteral("temp_lcdNumber_3"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        temp_lcdNumber_3->setPalette(palette2);
        temp_lcdNumber_3->setDigitCount(7);

        OxTankPressure->addWidget(temp_lcdNumber_3);


        verticalLayout->addLayout(OxTankPressure);

        FuelTankPressure = new QHBoxLayout();
        FuelTankPressure->setSpacing(6);
        FuelTankPressure->setObjectName(QStringLiteral("FuelTankPressure"));
        temp_label_4 = new QLabel(layoutWidget);
        temp_label_4->setObjectName(QStringLiteral("temp_label_4"));
        temp_label_4->setFont(font3);
        temp_label_4->setAlignment(Qt::AlignCenter);

        FuelTankPressure->addWidget(temp_label_4);

        temp_lcdNumber_4 = new QLCDNumber(layoutWidget);
        temp_lcdNumber_4->setObjectName(QStringLiteral("temp_lcdNumber_4"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        temp_lcdNumber_4->setPalette(palette3);
        temp_lcdNumber_4->setDigitCount(7);

        FuelTankPressure->addWidget(temp_lcdNumber_4);


        verticalLayout->addLayout(FuelTankPressure);

        OxPressure = new QHBoxLayout();
        OxPressure->setSpacing(6);
        OxPressure->setObjectName(QStringLiteral("OxPressure"));
        temp_label_6 = new QLabel(layoutWidget);
        temp_label_6->setObjectName(QStringLiteral("temp_label_6"));
        temp_label_6->setFont(font3);
        temp_label_6->setAlignment(Qt::AlignCenter);

        OxPressure->addWidget(temp_label_6);

        temp_lcdNumber_6 = new QLCDNumber(layoutWidget);
        temp_lcdNumber_6->setObjectName(QStringLiteral("temp_lcdNumber_6"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        temp_lcdNumber_6->setPalette(palette4);
        temp_lcdNumber_6->setDigitCount(7);

        OxPressure->addWidget(temp_lcdNumber_6);


        verticalLayout->addLayout(OxPressure);

        FuelPressure = new QHBoxLayout();
        FuelPressure->setSpacing(6);
        FuelPressure->setObjectName(QStringLiteral("FuelPressure"));
        temp_label_5 = new QLabel(layoutWidget);
        temp_label_5->setObjectName(QStringLiteral("temp_label_5"));
        temp_label_5->setFont(font3);
        temp_label_5->setAlignment(Qt::AlignCenter);

        FuelPressure->addWidget(temp_label_5);

        temp_lcdNumber_5 = new QLCDNumber(layoutWidget);
        temp_lcdNumber_5->setObjectName(QStringLiteral("temp_lcdNumber_5"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        temp_lcdNumber_5->setPalette(palette5);
        temp_lcdNumber_5->setDigitCount(7);

        FuelPressure->addWidget(temp_lcdNumber_5);


        verticalLayout->addLayout(FuelPressure);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        StateTitle->setText(QApplication::translate("Dialog", "SOLENOID STATES", nullptr));
        EnginePurgeLabel->setText(QApplication::translate("Dialog", "Engine Purge:", nullptr));
        EnginePurgeState->setText(QApplication::translate("Dialog", "CLOSED", nullptr));
        LOXPressLabel->setText(QApplication::translate("Dialog", "LOX Press:", nullptr));
        LOXPressState->setText(QApplication::translate("Dialog", "CLOSED", nullptr));
        LOXVentLabel->setText(QApplication::translate("Dialog", "LOX Vent:", nullptr));
        LOXVentState->setText(QApplication::translate("Dialog", "CLOSED", nullptr));
        InjectorChillLabel->setText(QApplication::translate("Dialog", "Injector Chill:", nullptr));
        InjectorChillState->setText(QApplication::translate("Dialog", "CLOSED", nullptr));
        LOXMainLabel->setText(QApplication::translate("Dialog", "LOX Main:", nullptr));
        LOXMainState->setText(QApplication::translate("Dialog", "CLOSED", nullptr));
        FuelPressLabel->setText(QApplication::translate("Dialog", "Fuel Press:", nullptr));
        FuelPressState->setText(QApplication::translate("Dialog", "CLOSED", nullptr));
        FuelPreLabel->setText(QApplication::translate("Dialog", "Fuel Pre-Stage:", nullptr));
        FuelPreState->setText(QApplication::translate("Dialog", "CLOSED", nullptr));
        FuelMainLabel->setText(QApplication::translate("Dialog", "Fuel Main:", nullptr));
        FuelMainState->setText(QApplication::translate("Dialog", "CLOSED", nullptr));
        temp_label->setText(QApplication::translate("Dialog", "<html><head/><body><p>Thermocouple 1 Temperature</p></body></html>", nullptr));
        temp_label_2->setText(QApplication::translate("Dialog", "<html><head/><body><p>Thermocouple 2 Temperature</p></body></html>", nullptr));
        temp_label_3->setText(QApplication::translate("Dialog", "<html><head/><body><p>LOX Tank Pressure</p></body></html>", nullptr));
        temp_label_4->setText(QApplication::translate("Dialog", "<html><head/><body><p>Fuel Tank Pressure</p></body></html>", nullptr));
        temp_label_6->setText(QApplication::translate("Dialog", "<html><head/><body><p>LOX Pressure</p></body></html>", nullptr));
        temp_label_5->setText(QApplication::translate("Dialog", "<html><head/><body><p>Fuel Pressure</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
