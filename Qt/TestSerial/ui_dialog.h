/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
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
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *Readouts;
    QHBoxLayout *Thermocouple1;
    QLabel *temp_label;
    QLCDNumber *temp1_display;
    QHBoxLayout *Thermocouple2;
    QLabel *temp_label_2;
    QLCDNumber *temp2_display;
    QHBoxLayout *OxTankPressure;
    QLabel *temp_label_3;
    QLCDNumber *pressure1_display;
    QHBoxLayout *FuelTankPressure;
    QLabel *temp_label_4;
    QLCDNumber *pressure2_display;
    QHBoxLayout *OxPressure;
    QLabel *temp_label_6;
    QLCDNumber *pressure3_display;
    QHBoxLayout *FuelPressure;
    QLabel *temp_label_5;
    QLCDNumber *pressure4_display;
    QVBoxLayout *SolenoidStates;
    QLabel *recordingLabel;
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

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(800, 600);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        Dialog->setFont(font);
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 10, 771, 501));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Readouts = new QVBoxLayout();
        Readouts->setSpacing(6);
        Readouts->setObjectName(QStringLiteral("Readouts"));
        Thermocouple1 = new QHBoxLayout();
        Thermocouple1->setSpacing(6);
        Thermocouple1->setObjectName(QStringLiteral("Thermocouple1"));
        Thermocouple1->setSizeConstraint(QLayout::SetFixedSize);
        temp_label = new QLabel(widget);
        temp_label->setObjectName(QStringLiteral("temp_label"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        temp_label->setFont(font1);
        temp_label->setAlignment(Qt::AlignCenter);

        Thermocouple1->addWidget(temp_label);

        temp1_display = new QLCDNumber(widget);
        temp1_display->setObjectName(QStringLiteral("temp1_display"));
        temp1_display->setMinimumSize(QSize(187, 77));
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
        temp1_display->setPalette(palette);
        temp1_display->setDigitCount(7);

        Thermocouple1->addWidget(temp1_display);


        Readouts->addLayout(Thermocouple1);

        Thermocouple2 = new QHBoxLayout();
        Thermocouple2->setSpacing(6);
        Thermocouple2->setObjectName(QStringLiteral("Thermocouple2"));
        temp_label_2 = new QLabel(widget);
        temp_label_2->setObjectName(QStringLiteral("temp_label_2"));
        temp_label_2->setFont(font1);
        temp_label_2->setAlignment(Qt::AlignCenter);

        Thermocouple2->addWidget(temp_label_2);

        temp2_display = new QLCDNumber(widget);
        temp2_display->setObjectName(QStringLiteral("temp2_display"));
        temp2_display->setMinimumSize(QSize(187, 77));
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
        temp2_display->setPalette(palette1);
        temp2_display->setDigitCount(7);

        Thermocouple2->addWidget(temp2_display);


        Readouts->addLayout(Thermocouple2);

        OxTankPressure = new QHBoxLayout();
        OxTankPressure->setSpacing(6);
        OxTankPressure->setObjectName(QStringLiteral("OxTankPressure"));
        temp_label_3 = new QLabel(widget);
        temp_label_3->setObjectName(QStringLiteral("temp_label_3"));
        temp_label_3->setFont(font1);
        temp_label_3->setAlignment(Qt::AlignCenter);

        OxTankPressure->addWidget(temp_label_3);

        pressure1_display = new QLCDNumber(widget);
        pressure1_display->setObjectName(QStringLiteral("pressure1_display"));
        pressure1_display->setMinimumSize(QSize(187, 77));
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
        pressure1_display->setPalette(palette2);
        pressure1_display->setDigitCount(7);

        OxTankPressure->addWidget(pressure1_display);


        Readouts->addLayout(OxTankPressure);

        FuelTankPressure = new QHBoxLayout();
        FuelTankPressure->setSpacing(6);
        FuelTankPressure->setObjectName(QStringLiteral("FuelTankPressure"));
        temp_label_4 = new QLabel(widget);
        temp_label_4->setObjectName(QStringLiteral("temp_label_4"));
        temp_label_4->setFont(font1);
        temp_label_4->setAlignment(Qt::AlignCenter);

        FuelTankPressure->addWidget(temp_label_4);

        pressure2_display = new QLCDNumber(widget);
        pressure2_display->setObjectName(QStringLiteral("pressure2_display"));
        pressure2_display->setMinimumSize(QSize(187, 77));
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
        pressure2_display->setPalette(palette3);
        pressure2_display->setDigitCount(7);

        FuelTankPressure->addWidget(pressure2_display);


        Readouts->addLayout(FuelTankPressure);

        OxPressure = new QHBoxLayout();
        OxPressure->setSpacing(6);
        OxPressure->setObjectName(QStringLiteral("OxPressure"));
        temp_label_6 = new QLabel(widget);
        temp_label_6->setObjectName(QStringLiteral("temp_label_6"));
        temp_label_6->setFont(font1);
        temp_label_6->setAlignment(Qt::AlignCenter);

        OxPressure->addWidget(temp_label_6);

        pressure3_display = new QLCDNumber(widget);
        pressure3_display->setObjectName(QStringLiteral("pressure3_display"));
        pressure3_display->setMinimumSize(QSize(187, 77));
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
        pressure3_display->setPalette(palette4);
        pressure3_display->setDigitCount(7);

        OxPressure->addWidget(pressure3_display);


        Readouts->addLayout(OxPressure);

        FuelPressure = new QHBoxLayout();
        FuelPressure->setSpacing(6);
        FuelPressure->setObjectName(QStringLiteral("FuelPressure"));
        temp_label_5 = new QLabel(widget);
        temp_label_5->setObjectName(QStringLiteral("temp_label_5"));
        temp_label_5->setFont(font1);
        temp_label_5->setAlignment(Qt::AlignCenter);

        FuelPressure->addWidget(temp_label_5);

        pressure4_display = new QLCDNumber(widget);
        pressure4_display->setObjectName(QStringLiteral("pressure4_display"));
        pressure4_display->setMinimumSize(QSize(187, 77));
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
        pressure4_display->setPalette(palette5);
        pressure4_display->setDigitCount(7);

        FuelPressure->addWidget(pressure4_display);


        Readouts->addLayout(FuelPressure);


        horizontalLayout->addLayout(Readouts);

        SolenoidStates = new QVBoxLayout();
        SolenoidStates->setSpacing(6);
        SolenoidStates->setObjectName(QStringLiteral("SolenoidStates"));
        SolenoidStates->setSizeConstraint(QLayout::SetFixedSize);
        SolenoidStates->setContentsMargins(-1, -1, -1, 0);
        recordingLabel = new QLabel(widget);
        recordingLabel->setObjectName(QStringLiteral("recordingLabel"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        recordingLabel->setFont(font2);
        recordingLabel->setFrameShape(QFrame::Panel);
        recordingLabel->setTextFormat(Qt::PlainText);
        recordingLabel->setAlignment(Qt::AlignCenter);

        SolenoidStates->addWidget(recordingLabel);

        StateTitle = new QLabel(widget);
        StateTitle->setObjectName(QStringLiteral("StateTitle"));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        StateTitle->setFont(font3);
        StateTitle->setAutoFillBackground(false);
        StateTitle->setFrameShape(QFrame::Box);
        StateTitle->setFrameShadow(QFrame::Plain);
        StateTitle->setTextFormat(Qt::RichText);
        StateTitle->setAlignment(Qt::AlignCenter);

        SolenoidStates->addWidget(StateTitle);

        EnginePurge = new QHBoxLayout();
        EnginePurge->setSpacing(6);
        EnginePurge->setObjectName(QStringLiteral("EnginePurge"));
        EnginePurge->setSizeConstraint(QLayout::SetFixedSize);
        EnginePurgeLabel = new QLabel(widget);
        EnginePurgeLabel->setObjectName(QStringLiteral("EnginePurgeLabel"));
        QFont font4;
        font4.setPointSize(12);
        EnginePurgeLabel->setFont(font4);
        EnginePurgeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        EnginePurge->addWidget(EnginePurgeLabel);

        EnginePurgeState = new QLabel(widget);
        EnginePurgeState->setObjectName(QStringLiteral("EnginePurgeState"));
        EnginePurgeState->setEnabled(true);
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        EnginePurgeState->setFont(font5);
        EnginePurgeState->setFrameShape(QFrame::Box);
        EnginePurgeState->setFrameShadow(QFrame::Raised);
        EnginePurgeState->setAlignment(Qt::AlignCenter);

        EnginePurge->addWidget(EnginePurgeState);


        SolenoidStates->addLayout(EnginePurge);

        LOXPress = new QHBoxLayout();
        LOXPress->setSpacing(6);
        LOXPress->setObjectName(QStringLiteral("LOXPress"));
        LOXPressLabel = new QLabel(widget);
        LOXPressLabel->setObjectName(QStringLiteral("LOXPressLabel"));
        LOXPressLabel->setFont(font4);
        LOXPressLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        LOXPress->addWidget(LOXPressLabel);

        LOXPressState = new QLabel(widget);
        LOXPressState->setObjectName(QStringLiteral("LOXPressState"));
        LOXPressState->setFont(font5);
        LOXPressState->setFrameShape(QFrame::Box);
        LOXPressState->setFrameShadow(QFrame::Raised);
        LOXPressState->setAlignment(Qt::AlignCenter);

        LOXPress->addWidget(LOXPressState);


        SolenoidStates->addLayout(LOXPress);

        LOXVent = new QHBoxLayout();
        LOXVent->setSpacing(6);
        LOXVent->setObjectName(QStringLiteral("LOXVent"));
        LOXVentLabel = new QLabel(widget);
        LOXVentLabel->setObjectName(QStringLiteral("LOXVentLabel"));
        LOXVentLabel->setFont(font4);
        LOXVentLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        LOXVent->addWidget(LOXVentLabel);

        LOXVentState = new QLabel(widget);
        LOXVentState->setObjectName(QStringLiteral("LOXVentState"));
        LOXVentState->setFont(font5);
        LOXVentState->setFrameShape(QFrame::Box);
        LOXVentState->setFrameShadow(QFrame::Raised);
        LOXVentState->setAlignment(Qt::AlignCenter);

        LOXVent->addWidget(LOXVentState);


        SolenoidStates->addLayout(LOXVent);

        InjectorChill = new QHBoxLayout();
        InjectorChill->setSpacing(6);
        InjectorChill->setObjectName(QStringLiteral("InjectorChill"));
        InjectorChillLabel = new QLabel(widget);
        InjectorChillLabel->setObjectName(QStringLiteral("InjectorChillLabel"));
        InjectorChillLabel->setFont(font4);
        InjectorChillLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        InjectorChill->addWidget(InjectorChillLabel);

        InjectorChillState = new QLabel(widget);
        InjectorChillState->setObjectName(QStringLiteral("InjectorChillState"));
        InjectorChillState->setFont(font5);
        InjectorChillState->setFrameShape(QFrame::Box);
        InjectorChillState->setFrameShadow(QFrame::Raised);
        InjectorChillState->setAlignment(Qt::AlignCenter);

        InjectorChill->addWidget(InjectorChillState);


        SolenoidStates->addLayout(InjectorChill);

        LOXMain = new QHBoxLayout();
        LOXMain->setSpacing(6);
        LOXMain->setObjectName(QStringLiteral("LOXMain"));
        LOXMainLabel = new QLabel(widget);
        LOXMainLabel->setObjectName(QStringLiteral("LOXMainLabel"));
        LOXMainLabel->setFont(font4);
        LOXMainLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        LOXMain->addWidget(LOXMainLabel);

        LOXMainState = new QLabel(widget);
        LOXMainState->setObjectName(QStringLiteral("LOXMainState"));
        LOXMainState->setFont(font5);
        LOXMainState->setFrameShape(QFrame::Box);
        LOXMainState->setFrameShadow(QFrame::Raised);
        LOXMainState->setAlignment(Qt::AlignCenter);

        LOXMain->addWidget(LOXMainState);


        SolenoidStates->addLayout(LOXMain);

        FuelPress = new QHBoxLayout();
        FuelPress->setSpacing(6);
        FuelPress->setObjectName(QStringLiteral("FuelPress"));
        FuelPressLabel = new QLabel(widget);
        FuelPressLabel->setObjectName(QStringLiteral("FuelPressLabel"));
        FuelPressLabel->setFont(font4);
        FuelPressLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        FuelPress->addWidget(FuelPressLabel);

        FuelPressState = new QLabel(widget);
        FuelPressState->setObjectName(QStringLiteral("FuelPressState"));
        FuelPressState->setFont(font5);
        FuelPressState->setFrameShape(QFrame::Box);
        FuelPressState->setFrameShadow(QFrame::Raised);
        FuelPressState->setAlignment(Qt::AlignCenter);

        FuelPress->addWidget(FuelPressState);


        SolenoidStates->addLayout(FuelPress);

        FuelPre = new QHBoxLayout();
        FuelPre->setSpacing(6);
        FuelPre->setObjectName(QStringLiteral("FuelPre"));
        FuelPreLabel = new QLabel(widget);
        FuelPreLabel->setObjectName(QStringLiteral("FuelPreLabel"));
        FuelPreLabel->setFont(font4);
        FuelPreLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        FuelPre->addWidget(FuelPreLabel);

        FuelPreState = new QLabel(widget);
        FuelPreState->setObjectName(QStringLiteral("FuelPreState"));
        FuelPreState->setFont(font5);
        FuelPreState->setFrameShape(QFrame::Box);
        FuelPreState->setFrameShadow(QFrame::Raised);
        FuelPreState->setAlignment(Qt::AlignCenter);

        FuelPre->addWidget(FuelPreState);


        SolenoidStates->addLayout(FuelPre);

        FuelMain = new QHBoxLayout();
        FuelMain->setSpacing(6);
        FuelMain->setObjectName(QStringLiteral("FuelMain"));
        FuelMainLabel = new QLabel(widget);
        FuelMainLabel->setObjectName(QStringLiteral("FuelMainLabel"));
        FuelMainLabel->setFont(font4);
        FuelMainLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        FuelMain->addWidget(FuelMainLabel);

        FuelMainState = new QLabel(widget);
        FuelMainState->setObjectName(QStringLiteral("FuelMainState"));
        FuelMainState->setFont(font5);
        FuelMainState->setFrameShape(QFrame::Box);
        FuelMainState->setFrameShadow(QFrame::Raised);
        FuelMainState->setAlignment(Qt::AlignCenter);

        FuelMain->addWidget(FuelMainState);


        SolenoidStates->addLayout(FuelMain);


        horizontalLayout->addLayout(SolenoidStates);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        temp_label->setText(QApplication::translate("Dialog", "<html><head/><body><p>TC 1 Temperature</p></body></html>", Q_NULLPTR));
        temp_label_2->setText(QApplication::translate("Dialog", "<html><head/><body><p>TC 2 Temperature</p></body></html>", Q_NULLPTR));
        temp_label_3->setText(QApplication::translate("Dialog", "<html><head/><body><p>PT1 (F-INJECTOR)</p></body></html>", Q_NULLPTR));
        temp_label_4->setText(QApplication::translate("Dialog", "<html><head/><body><p>PT2</p></body></html>", Q_NULLPTR));
        temp_label_6->setText(QApplication::translate("Dialog", "<html><head/><body><p>PT3 (FUEL TANK)</p></body></html>", Q_NULLPTR));
        temp_label_5->setText(QApplication::translate("Dialog", "<html><head/><body><p>PT4</p></body></html>", Q_NULLPTR));
        recordingLabel->setText(QApplication::translate("Dialog", "RECORDING: OFF", Q_NULLPTR));
        StateTitle->setText(QApplication::translate("Dialog", "SOLENOID STATES", Q_NULLPTR));
        EnginePurgeLabel->setText(QApplication::translate("Dialog", "Engine Purge:", Q_NULLPTR));
        EnginePurgeState->setText(QApplication::translate("Dialog", "CLOSED", Q_NULLPTR));
        LOXPressLabel->setText(QApplication::translate("Dialog", "LOX Press", Q_NULLPTR));
        LOXPressState->setText(QApplication::translate("Dialog", "CLOSED", Q_NULLPTR));
        LOXVentLabel->setText(QApplication::translate("Dialog", "LOX Vent:", Q_NULLPTR));
        LOXVentState->setText(QApplication::translate("Dialog", "CLOSED", Q_NULLPTR));
        InjectorChillLabel->setText(QApplication::translate("Dialog", "Injector Chill:", Q_NULLPTR));
        InjectorChillState->setText(QApplication::translate("Dialog", "INHIBIT", Q_NULLPTR));
        LOXMainLabel->setText(QApplication::translate("Dialog", "LOX Main:", Q_NULLPTR));
        LOXMainState->setText(QApplication::translate("Dialog", "INHIBIT", Q_NULLPTR));
        FuelPressLabel->setText(QApplication::translate("Dialog", "Fuel Press:", Q_NULLPTR));
        FuelPressState->setText(QApplication::translate("Dialog", "CLOSED", Q_NULLPTR));
        FuelPreLabel->setText(QApplication::translate("Dialog", "Fuel Pre-Stage:", Q_NULLPTR));
        FuelPreState->setText(QApplication::translate("Dialog", "INHIBIT", Q_NULLPTR));
        FuelMainLabel->setText(QApplication::translate("Dialog", "Fuel Main:", Q_NULLPTR));
        FuelMainState->setText(QApplication::translate("Dialog", "INHIBIT", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
