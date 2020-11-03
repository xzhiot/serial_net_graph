#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>

#include <QFile>
#include <QFileDialog>

#include <QtCharts>
#include "QLineSeries"
#include "QValueAxis"
#include "QTimer"
#include "QTime"
#include "QList"
#include "qmath.h"
#include "QPointF"
#include "QDebug"
#include "QChartView"
#include "dataprocess.h"
#include <QMutex>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QtNetwork>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

#define Channel_number 20



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void readData();
    //void socket_Read_Data();
    void socket_Disconnected();
    void server_New_Connect();
    //void udp_receive();

    void on_btn_OpenSerial_clicked();

    void on_btn_help_clicked();

    void on_btn_StopDis_clicked();

    void on_action_save_triggered();

    void on_action_load_triggered();

    void on_btn_ClearSeries_clicked();

    void on_btn_SetXSize_clicked();

    void on_CH1_stateChanged();
    void on_CH2_stateChanged();
    void on_CH3_stateChanged();
    void on_CH4_stateChanged();
    void on_CH5_stateChanged();
    void on_CH6_stateChanged();
    void on_CH7_stateChanged();
    void on_CH8_stateChanged();
    void on_CH9_stateChanged();
    void on_CH10_stateChanged();
    void on_CH11_stateChanged();
    void on_CH12_stateChanged();
    void on_CH13_stateChanged();
    void on_CH14_stateChanged();
    void on_CH15_stateChanged();
    void on_CH16_stateChanged();
    void on_CH17_stateChanged();
    void on_CH18_stateChanged();
    void on_CH19_stateChanged();
    void on_CH20_stateChanged();

    void writeData(char* data,unsigned int len);

    void on_BTNSEND_clicked();

    void on_HEXSND_stateChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_periodsend_stateChanged();

    void on_period_sends();

    void on_cb_SerialPort_activated();


private:
    QString writeDataToCSV();
    void readDataFromCSV(QTextStream &sDataStream);
    void string2hex(QByteArray sendcoms);
    void hex2string(QByteArray &rcvstring);
//    void dispformat(QString appendStr);
private:
    bool SerialSta;
    DataProcess processor;
    bool chartSta;
    QSerialPort *port;
    Ui::MainWindow *ui;
    QLabel *lb_StatusBar_SerialStatus;
    QLabel *lb_StatusBar_DataRecNum;

    QChart *m_chart;
    QLineSeries m_series[Channel_number];
    QVector<QPointF> points[Channel_number];
    QValueAxis *axisX;
    QValueAxis *axisY;

    bool selchx[20];
    unsigned long int dataRecNum=0;
    int XSize = 200;
    int timeId;
    int Xmin=0;
    int Xmax=0;
    float Ymin=3.4028235e38f;
    float Ymax=1.4e-45f;
    QByteArray sendbuff;
    QString recvbuff;
    QTimer *sendTimer;// 定时器对象
    uint16_t rcvmaxsize;
    bool recvconvf;
    QString displaystr;
    QMutex mutex;
    QStringList baudspeed;
    uint8_t commethflag;
    QTcpServer* server;
    QTcpSocket* socket;
    QList<QTcpSocket*> tcpClient;
    QUdpSocket *uSocket;
    QString ipAddr;
    QTcpSocket* TCPCSocket;

    QHostAddress udpfromhost;
    quint16 udpfromport;
    bool bditemf;
    //QList<QHostAddress> ipAddressesList;

};

#endif // MAINWINDOW_H
