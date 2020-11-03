/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_save;
    QAction *action_load;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QtCharts::QChartView *chartView;
    QHBoxLayout *horizontalLayout_4;
    QLabel *LBL1;
    QLineEdit *lineEdit_3;
    QLabel *LBL2;
    QLineEdit *lineEdit_2;
    QLabel *LBL3;
    QLineEdit *lineEdit;
    QLabel *LBL4;
    QLineEdit *lineEdit_5;
    QLabel *LBL5;
    QLineEdit *lineEdit_4;
    QLabel *LBL6;
    QLineEdit *lineEdit_6;
    QLabel *LBL7;
    QLineEdit *lineEdit_7;
    QLabel *LBL8;
    QLineEdit *lineEdit_8;
    QLabel *LBL9;
    QLineEdit *lineEdit_15;
    QLabel *LBL10;
    QLineEdit *lineEdit_9;
    QLabel *LBL11;
    QLineEdit *lineEdit_13;
    QLabel *LBL12;
    QLineEdit *lineEdit_14;
    QLabel *LBL13;
    QLineEdit *lineEdit_12;
    QLabel *LBL14;
    QLineEdit *lineEdit_11;
    QLabel *LBL15;
    QLineEdit *lineEdit_10;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *CH1;
    QCheckBox *CH2;
    QCheckBox *CH3;
    QCheckBox *CH4;
    QCheckBox *CH5;
    QCheckBox *CH6;
    QCheckBox *CH7;
    QCheckBox *CH8;
    QCheckBox *CH9;
    QCheckBox *CH20;
    QCheckBox *CH10;
    QCheckBox *CH11;
    QCheckBox *CH12;
    QCheckBox *CH13;
    QCheckBox *CH14;
    QCheckBox *CH15;
    QCheckBox *CH16;
    QCheckBox *CH17;
    QCheckBox *CH18;
    QCheckBox *CH19;
    QHBoxLayout *horizontalLayout_14;
    QTextBrowser *RCVAREA;
    QHBoxLayout *horizontalLayout_6;
    QTextEdit *sendmulcom;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *HEXRCV;
    QCheckBox *HEXSND;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *periodsend;
    QLineEdit *lineEdit_16;
    QPushButton *BTNSEND;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_17;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_18;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *lineEdit_19;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEdit_20;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *lineEdit_21;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *lineEdit_22;
    QPushButton *pushButton_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cb_SerialPort;
    QLabel *label_2;
    QComboBox *cb_baudRate;
    QLineEdit *Connect_ADDR;
    QPushButton *btn_OpenSerial;
    QPushButton *btn_StopDis;
    QPushButton *btn_ClearSeries;
    QPushButton *btn_SetXSize;
    QLineEdit *leXSize;
    QCheckBox *checkBoxXAuto;
    QCheckBox *checkBoxYAuto;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_help;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1185, 804);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_save = new QAction(MainWindow);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        action_load = new QAction(MainWindow);
        action_load->setObjectName(QString::fromUtf8("action_load"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        chartView = new QtCharts::QChartView(centralWidget);
        chartView->setObjectName(QString::fromUtf8("chartView"));
        chartView->setMinimumSize(QSize(0, 320));

        verticalLayout_4->addWidget(chartView);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        LBL1 = new QLabel(centralWidget);
        LBL1->setObjectName(QString::fromUtf8("LBL1"));

        horizontalLayout_4->addWidget(LBL1);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_4->addWidget(lineEdit_3);

        LBL2 = new QLabel(centralWidget);
        LBL2->setObjectName(QString::fromUtf8("LBL2"));

        horizontalLayout_4->addWidget(LBL2);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_4->addWidget(lineEdit_2);

        LBL3 = new QLabel(centralWidget);
        LBL3->setObjectName(QString::fromUtf8("LBL3"));

        horizontalLayout_4->addWidget(LBL3);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);

        LBL4 = new QLabel(centralWidget);
        LBL4->setObjectName(QString::fromUtf8("LBL4"));

        horizontalLayout_4->addWidget(LBL4);

        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_4->addWidget(lineEdit_5);

        LBL5 = new QLabel(centralWidget);
        LBL5->setObjectName(QString::fromUtf8("LBL5"));

        horizontalLayout_4->addWidget(LBL5);

        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_4->addWidget(lineEdit_4);

        LBL6 = new QLabel(centralWidget);
        LBL6->setObjectName(QString::fromUtf8("LBL6"));

        horizontalLayout_4->addWidget(LBL6);

        lineEdit_6 = new QLineEdit(centralWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_4->addWidget(lineEdit_6);

        LBL7 = new QLabel(centralWidget);
        LBL7->setObjectName(QString::fromUtf8("LBL7"));

        horizontalLayout_4->addWidget(LBL7);

        lineEdit_7 = new QLineEdit(centralWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        horizontalLayout_4->addWidget(lineEdit_7);

        LBL8 = new QLabel(centralWidget);
        LBL8->setObjectName(QString::fromUtf8("LBL8"));

        horizontalLayout_4->addWidget(LBL8);

        lineEdit_8 = new QLineEdit(centralWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        horizontalLayout_4->addWidget(lineEdit_8);

        LBL9 = new QLabel(centralWidget);
        LBL9->setObjectName(QString::fromUtf8("LBL9"));

        horizontalLayout_4->addWidget(LBL9);

        lineEdit_15 = new QLineEdit(centralWidget);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));

        horizontalLayout_4->addWidget(lineEdit_15);

        LBL10 = new QLabel(centralWidget);
        LBL10->setObjectName(QString::fromUtf8("LBL10"));

        horizontalLayout_4->addWidget(LBL10);

        lineEdit_9 = new QLineEdit(centralWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        horizontalLayout_4->addWidget(lineEdit_9);

        LBL11 = new QLabel(centralWidget);
        LBL11->setObjectName(QString::fromUtf8("LBL11"));

        horizontalLayout_4->addWidget(LBL11);

        lineEdit_13 = new QLineEdit(centralWidget);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));

        horizontalLayout_4->addWidget(lineEdit_13);

        LBL12 = new QLabel(centralWidget);
        LBL12->setObjectName(QString::fromUtf8("LBL12"));

        horizontalLayout_4->addWidget(LBL12);

        lineEdit_14 = new QLineEdit(centralWidget);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));

        horizontalLayout_4->addWidget(lineEdit_14);

        LBL13 = new QLabel(centralWidget);
        LBL13->setObjectName(QString::fromUtf8("LBL13"));

        horizontalLayout_4->addWidget(LBL13);

        lineEdit_12 = new QLineEdit(centralWidget);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));

        horizontalLayout_4->addWidget(lineEdit_12);

        LBL14 = new QLabel(centralWidget);
        LBL14->setObjectName(QString::fromUtf8("LBL14"));

        horizontalLayout_4->addWidget(LBL14);

        lineEdit_11 = new QLineEdit(centralWidget);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        horizontalLayout_4->addWidget(lineEdit_11);

        LBL15 = new QLabel(centralWidget);
        LBL15->setObjectName(QString::fromUtf8("LBL15"));

        horizontalLayout_4->addWidget(LBL15);

        lineEdit_10 = new QLineEdit(centralWidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        horizontalLayout_4->addWidget(lineEdit_10);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        CH1 = new QCheckBox(centralWidget);
        CH1->setObjectName(QString::fromUtf8("CH1"));
        CH1->setChecked(true);

        horizontalLayout_2->addWidget(CH1);

        CH2 = new QCheckBox(centralWidget);
        CH2->setObjectName(QString::fromUtf8("CH2"));
        CH2->setChecked(true);

        horizontalLayout_2->addWidget(CH2);

        CH3 = new QCheckBox(centralWidget);
        CH3->setObjectName(QString::fromUtf8("CH3"));

        horizontalLayout_2->addWidget(CH3);

        CH4 = new QCheckBox(centralWidget);
        CH4->setObjectName(QString::fromUtf8("CH4"));

        horizontalLayout_2->addWidget(CH4);

        CH5 = new QCheckBox(centralWidget);
        CH5->setObjectName(QString::fromUtf8("CH5"));

        horizontalLayout_2->addWidget(CH5);

        CH6 = new QCheckBox(centralWidget);
        CH6->setObjectName(QString::fromUtf8("CH6"));

        horizontalLayout_2->addWidget(CH6);

        CH7 = new QCheckBox(centralWidget);
        CH7->setObjectName(QString::fromUtf8("CH7"));

        horizontalLayout_2->addWidget(CH7);

        CH8 = new QCheckBox(centralWidget);
        CH8->setObjectName(QString::fromUtf8("CH8"));

        horizontalLayout_2->addWidget(CH8);

        CH9 = new QCheckBox(centralWidget);
        CH9->setObjectName(QString::fromUtf8("CH9"));

        horizontalLayout_2->addWidget(CH9);

        CH20 = new QCheckBox(centralWidget);
        CH20->setObjectName(QString::fromUtf8("CH20"));

        horizontalLayout_2->addWidget(CH20);

        CH10 = new QCheckBox(centralWidget);
        CH10->setObjectName(QString::fromUtf8("CH10"));

        horizontalLayout_2->addWidget(CH10);

        CH11 = new QCheckBox(centralWidget);
        CH11->setObjectName(QString::fromUtf8("CH11"));

        horizontalLayout_2->addWidget(CH11);

        CH12 = new QCheckBox(centralWidget);
        CH12->setObjectName(QString::fromUtf8("CH12"));

        horizontalLayout_2->addWidget(CH12);

        CH13 = new QCheckBox(centralWidget);
        CH13->setObjectName(QString::fromUtf8("CH13"));

        horizontalLayout_2->addWidget(CH13);

        CH14 = new QCheckBox(centralWidget);
        CH14->setObjectName(QString::fromUtf8("CH14"));

        horizontalLayout_2->addWidget(CH14);

        CH15 = new QCheckBox(centralWidget);
        CH15->setObjectName(QString::fromUtf8("CH15"));

        horizontalLayout_2->addWidget(CH15);

        CH16 = new QCheckBox(centralWidget);
        CH16->setObjectName(QString::fromUtf8("CH16"));

        horizontalLayout_2->addWidget(CH16);

        CH17 = new QCheckBox(centralWidget);
        CH17->setObjectName(QString::fromUtf8("CH17"));

        horizontalLayout_2->addWidget(CH17);

        CH18 = new QCheckBox(centralWidget);
        CH18->setObjectName(QString::fromUtf8("CH18"));

        horizontalLayout_2->addWidget(CH18);

        CH19 = new QCheckBox(centralWidget);
        CH19->setObjectName(QString::fromUtf8("CH19"));

        horizontalLayout_2->addWidget(CH19);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        RCVAREA = new QTextBrowser(centralWidget);
        RCVAREA->setObjectName(QString::fromUtf8("RCVAREA"));
        RCVAREA->setMinimumSize(QSize(0, 120));
        RCVAREA->setMaximumSize(QSize(16777215, 360));

        horizontalLayout_14->addWidget(RCVAREA);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        sendmulcom = new QTextEdit(centralWidget);
        sendmulcom->setObjectName(QString::fromUtf8("sendmulcom"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sendmulcom->sizePolicy().hasHeightForWidth());
        sendmulcom->setSizePolicy(sizePolicy);
        sendmulcom->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_6->addWidget(sendmulcom);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        HEXRCV = new QCheckBox(centralWidget);
        HEXRCV->setObjectName(QString::fromUtf8("HEXRCV"));

        verticalLayout_3->addWidget(HEXRCV);

        HEXSND = new QCheckBox(centralWidget);
        HEXSND->setObjectName(QString::fromUtf8("HEXSND"));

        verticalLayout_3->addWidget(HEXSND);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        periodsend = new QCheckBox(centralWidget);
        periodsend->setObjectName(QString::fromUtf8("periodsend"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(periodsend->sizePolicy().hasHeightForWidth());
        periodsend->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(periodsend);

        lineEdit_16 = new QLineEdit(centralWidget);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));
        lineEdit_16->setMaximumSize(QSize(60, 20));

        horizontalLayout_8->addWidget(lineEdit_16);


        verticalLayout_3->addLayout(horizontalLayout_8);

        BTNSEND = new QPushButton(centralWidget);
        BTNSEND->setObjectName(QString::fromUtf8("BTNSEND"));

        verticalLayout_3->addWidget(BTNSEND);


        horizontalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEdit_17 = new QLineEdit(centralWidget);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));
        sizePolicy1.setHeightForWidth(lineEdit_17->sizePolicy().hasHeightForWidth());
        lineEdit_17->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(lineEdit_17);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMaximumSize(QSize(60, 20));
        pushButton->setIconSize(QSize(16, 16));

        horizontalLayout_5->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lineEdit_18 = new QLineEdit(centralWidget);
        lineEdit_18->setObjectName(QString::fromUtf8("lineEdit_18"));
        sizePolicy1.setHeightForWidth(lineEdit_18->sizePolicy().hasHeightForWidth());
        lineEdit_18->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lineEdit_18);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(60, 20));

        horizontalLayout_7->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lineEdit_19 = new QLineEdit(centralWidget);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));
        sizePolicy1.setHeightForWidth(lineEdit_19->sizePolicy().hasHeightForWidth());
        lineEdit_19->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(lineEdit_19);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(60, 20));

        horizontalLayout_9->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        lineEdit_20 = new QLineEdit(centralWidget);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));
        sizePolicy1.setHeightForWidth(lineEdit_20->sizePolicy().hasHeightForWidth());
        lineEdit_20->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(lineEdit_20);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(60, 20));

        horizontalLayout_10->addWidget(pushButton_4);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        lineEdit_21 = new QLineEdit(centralWidget);
        lineEdit_21->setObjectName(QString::fromUtf8("lineEdit_21"));
        sizePolicy1.setHeightForWidth(lineEdit_21->sizePolicy().hasHeightForWidth());
        lineEdit_21->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(lineEdit_21);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(60, 20));

        horizontalLayout_11->addWidget(pushButton_5);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        lineEdit_22 = new QLineEdit(centralWidget);
        lineEdit_22->setObjectName(QString::fromUtf8("lineEdit_22"));
        sizePolicy1.setHeightForWidth(lineEdit_22->sizePolicy().hasHeightForWidth());
        lineEdit_22->setSizePolicy(sizePolicy1);

        horizontalLayout_13->addWidget(lineEdit_22);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMaximumSize(QSize(60, 20));

        horizontalLayout_13->addWidget(pushButton_6);


        verticalLayout_2->addLayout(horizontalLayout_13);


        horizontalLayout_6->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, -1, 10, -1);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cb_SerialPort = new QComboBox(centralWidget);
        cb_SerialPort->setObjectName(QString::fromUtf8("cb_SerialPort"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cb_SerialPort->sizePolicy().hasHeightForWidth());
        cb_SerialPort->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(cb_SerialPort);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        cb_baudRate = new QComboBox(centralWidget);
        cb_baudRate->addItem(QString());
        cb_baudRate->addItem(QString());
        cb_baudRate->addItem(QString());
        cb_baudRate->addItem(QString());
        cb_baudRate->addItem(QString());
        cb_baudRate->addItem(QString());
        cb_baudRate->addItem(QString());
        cb_baudRate->addItem(QString());
        cb_baudRate->addItem(QString());
        cb_baudRate->addItem(QString());
        cb_baudRate->addItem(QString());
        cb_baudRate->addItem(QString());
        cb_baudRate->setObjectName(QString::fromUtf8("cb_baudRate"));
        sizePolicy2.setHeightForWidth(cb_baudRate->sizePolicy().hasHeightForWidth());
        cb_baudRate->setSizePolicy(sizePolicy2);
        cb_baudRate->setEditable(true);

        horizontalLayout->addWidget(cb_baudRate);

        Connect_ADDR = new QLineEdit(centralWidget);
        Connect_ADDR->setObjectName(QString::fromUtf8("Connect_ADDR"));
        Connect_ADDR->setEnabled(false);
        Connect_ADDR->setMinimumSize(QSize(120, 0));
        Connect_ADDR->setMaximumSize(QSize(16777215, 16777215));
        Connect_ADDR->setReadOnly(false);

        horizontalLayout->addWidget(Connect_ADDR);

        btn_OpenSerial = new QPushButton(centralWidget);
        btn_OpenSerial->setObjectName(QString::fromUtf8("btn_OpenSerial"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btn_OpenSerial->sizePolicy().hasHeightForWidth());
        btn_OpenSerial->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(btn_OpenSerial);

        btn_StopDis = new QPushButton(centralWidget);
        btn_StopDis->setObjectName(QString::fromUtf8("btn_StopDis"));
        sizePolicy3.setHeightForWidth(btn_StopDis->sizePolicy().hasHeightForWidth());
        btn_StopDis->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(btn_StopDis);

        btn_ClearSeries = new QPushButton(centralWidget);
        btn_ClearSeries->setObjectName(QString::fromUtf8("btn_ClearSeries"));

        horizontalLayout->addWidget(btn_ClearSeries);

        btn_SetXSize = new QPushButton(centralWidget);
        btn_SetXSize->setObjectName(QString::fromUtf8("btn_SetXSize"));

        horizontalLayout->addWidget(btn_SetXSize);

        leXSize = new QLineEdit(centralWidget);
        leXSize->setObjectName(QString::fromUtf8("leXSize"));
        leXSize->setMaxLength(5);
        leXSize->setFrame(true);
        leXSize->setCursorMoveStyle(Qt::LogicalMoveStyle);
        leXSize->setClearButtonEnabled(false);

        horizontalLayout->addWidget(leXSize);

        checkBoxXAuto = new QCheckBox(centralWidget);
        checkBoxXAuto->setObjectName(QString::fromUtf8("checkBoxXAuto"));
        checkBoxXAuto->setChecked(true);

        horizontalLayout->addWidget(checkBoxXAuto);

        checkBoxYAuto = new QCheckBox(centralWidget);
        checkBoxYAuto->setObjectName(QString::fromUtf8("checkBoxYAuto"));
        checkBoxYAuto->setChecked(true);

        horizontalLayout->addWidget(checkBoxYAuto);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_help = new QPushButton(centralWidget);
        btn_help->setObjectName(QString::fromUtf8("btn_help"));

        horizontalLayout->addWidget(btn_help);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 2);
        horizontalLayout->setStretch(5, 2);
        horizontalLayout->setStretch(6, 2);
        horizontalLayout->setStretch(7, 2);
        horizontalLayout->setStretch(8, 2);
        horizontalLayout->setStretch(9, 1);
        horizontalLayout->setStretch(10, 1);
        horizontalLayout->setStretch(11, 1);
        horizontalLayout->setStretch(12, 10);

        verticalLayout_4->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1185, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_save);
        menu->addAction(action_load);

        retranslateUi(MainWindow);

        cb_baudRate->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\347\244\272\346\263\242\345\231\250", nullptr));
        action_save->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        action_load->setText(QCoreApplication::translate("MainWindow", "\350\275\275\345\205\245\346\225\260\346\215\256", nullptr));
        LBL1->setText(QCoreApplication::translate("MainWindow", "V1", nullptr));
        LBL2->setText(QCoreApplication::translate("MainWindow", "V2", nullptr));
        LBL3->setText(QCoreApplication::translate("MainWindow", "V3", nullptr));
        LBL4->setText(QCoreApplication::translate("MainWindow", "V4", nullptr));
        LBL5->setText(QCoreApplication::translate("MainWindow", "V5", nullptr));
        LBL6->setText(QCoreApplication::translate("MainWindow", "V6", nullptr));
        LBL7->setText(QCoreApplication::translate("MainWindow", "V7", nullptr));
        LBL8->setText(QCoreApplication::translate("MainWindow", "V8", nullptr));
        LBL9->setText(QCoreApplication::translate("MainWindow", "V9", nullptr));
        LBL10->setText(QCoreApplication::translate("MainWindow", "V10", nullptr));
        LBL11->setText(QCoreApplication::translate("MainWindow", "V11", nullptr));
        LBL12->setText(QCoreApplication::translate("MainWindow", "V12", nullptr));
        LBL13->setText(QCoreApplication::translate("MainWindow", "V13", nullptr));
        LBL14->setText(QCoreApplication::translate("MainWindow", "V14", nullptr));
        LBL15->setText(QCoreApplication::translate("MainWindow", "V15", nullptr));
        CH1->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH2->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH3->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH4->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH5->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH6->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH7->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH8->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH9->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH20->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH10->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH11->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH12->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH13->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH14->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH15->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH16->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH17->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH18->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        CH19->setText(QCoreApplication::translate("MainWindow", "CH", nullptr));
        HEXRCV->setText(QCoreApplication::translate("MainWindow", "16\350\277\233\345\210\266\346\216\245\346\224\266", nullptr));
        HEXSND->setText(QCoreApplication::translate("MainWindow", "16\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        periodsend->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        lineEdit_16->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        BTNSEND->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "DATA1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "DATA2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "DATA3", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "DATA4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "DATA5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "DATA6", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\200\232\344\277\241\346\226\271\345\274\217", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207/\347\253\257\345\217\243", nullptr));
        cb_baudRate->setItemText(0, QCoreApplication::translate("MainWindow", "2400", nullptr));
        cb_baudRate->setItemText(1, QCoreApplication::translate("MainWindow", "4800", nullptr));
        cb_baudRate->setItemText(2, QCoreApplication::translate("MainWindow", "9600", nullptr));
        cb_baudRate->setItemText(3, QCoreApplication::translate("MainWindow", "19200", nullptr));
        cb_baudRate->setItemText(4, QCoreApplication::translate("MainWindow", "38400", nullptr));
        cb_baudRate->setItemText(5, QCoreApplication::translate("MainWindow", "57600", nullptr));
        cb_baudRate->setItemText(6, QCoreApplication::translate("MainWindow", "76800", nullptr));
        cb_baudRate->setItemText(7, QCoreApplication::translate("MainWindow", "115200", nullptr));
        cb_baudRate->setItemText(8, QCoreApplication::translate("MainWindow", "153600", nullptr));
        cb_baudRate->setItemText(9, QCoreApplication::translate("MainWindow", "230400", nullptr));
        cb_baudRate->setItemText(10, QCoreApplication::translate("MainWindow", "500000", nullptr));
        cb_baudRate->setItemText(11, QCoreApplication::translate("MainWindow", "1000000", nullptr));

        btn_OpenSerial->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\220\257", nullptr));
        btn_StopDis->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\233\264\346\226\260", nullptr));
        btn_ClearSeries->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\346\233\262\347\272\277", nullptr));
        btn_SetXSize->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256X\350\214\203\345\233\264", nullptr));
        leXSize->setText(QCoreApplication::translate("MainWindow", "200", nullptr));
        checkBoxXAuto->setText(QCoreApplication::translate("MainWindow", "X\350\207\252\345\212\250", nullptr));
        checkBoxYAuto->setText(QCoreApplication::translate("MainWindow", "Y\350\207\252\345\212\250", nullptr));
        btn_help->setText(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
