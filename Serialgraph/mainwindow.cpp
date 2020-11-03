#include "mainwindow.h"
#include "ui_mainwindow.h"
/*曲线颜色*/
//调整次序
const int color[20]={
    0xff0000,0xffff00,0x00ff00,0x0000ff,0xff00ff,
    0xff8000,0xc0ff00,0x00ffff,0x8000ff,0x000001,
    0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,
};
/*const int color[10]={
    0xff0000,0xff8000,0xffff00,0xc0ff00,0x00ff00,
    0x00ffff,0x0000ff,0x8000ff,0xff00ff,0x000001,
};*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QStringList netstring = {"TCP Server","TCP Client","UDP"/*,"UDP Client"*/};


    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, ipAddressesList) {
            if (address.protocol() == QAbstractSocket::IPv4Protocol) {
                ipAddr = address.toString();
                break;
            }
        }

    baudspeed.append("2400");
    baudspeed.append("4800");
    baudspeed.append("9600");
    baudspeed.append("19200");
    baudspeed.append("38400");
    baudspeed.append("57600");
    baudspeed.append("115200");
    baudspeed.append("230400");
    baudspeed.append("500000");
    baudspeed.append("1000000");
    bditemf = 1;
    ui->setupUi(this);

    SerialSta=false;
    commethflag = false;
    port=new QSerialPort;
    connect(port,SIGNAL(readyRead()),this,SLOT(readData()));
    connect(ui->CH1, SIGNAL(stateChanged(int)), this, SLOT(on_CH1_stateChanged()));
    connect(ui->CH2, SIGNAL(stateChanged(int)), this, SLOT(on_CH2_stateChanged()));
    connect(ui->CH3, SIGNAL(stateChanged(int)), this, SLOT(on_CH3_stateChanged()));
    connect(ui->CH4, SIGNAL(stateChanged(int)), this, SLOT(on_CH4_stateChanged()));
    connect(ui->CH5, SIGNAL(stateChanged(int)), this, SLOT(on_CH5_stateChanged()));
    connect(ui->CH6, SIGNAL(stateChanged(int)), this, SLOT(on_CH6_stateChanged()));
    connect(ui->CH7, SIGNAL(stateChanged(int)), this, SLOT(on_CH7_stateChanged()));
    connect(ui->CH8, SIGNAL(stateChanged(int)), this, SLOT(on_CH8_stateChanged()));
    connect(ui->CH9, SIGNAL(stateChanged(int)), this, SLOT(on_CH9_stateChanged()));
    connect(ui->CH10, SIGNAL(stateChanged(int)), this, SLOT(on_CH10_stateChanged()));
    connect(ui->CH11, SIGNAL(stateChanged(int)), this, SLOT(on_CH11_stateChanged()));
    connect(ui->CH12, SIGNAL(stateChanged(int)), this, SLOT(on_CH12_stateChanged()));
    connect(ui->CH13, SIGNAL(stateChanged(int)), this, SLOT(on_CH13_stateChanged()));
    connect(ui->CH14, SIGNAL(stateChanged(int)), this, SLOT(on_CH14_stateChanged()));
    connect(ui->CH15, SIGNAL(stateChanged(int)), this, SLOT(on_CH15_stateChanged()));
    connect(ui->CH16, SIGNAL(stateChanged(int)), this, SLOT(on_CH16_stateChanged()));
    connect(ui->CH17, SIGNAL(stateChanged(int)), this, SLOT(on_CH17_stateChanged()));
    connect(ui->CH18, SIGNAL(stateChanged(int)), this, SLOT(on_CH18_stateChanged()));
    connect(ui->CH19, SIGNAL(stateChanged(int)), this, SLOT(on_CH19_stateChanged()));
    connect(ui->CH20, SIGNAL(stateChanged(int)), this, SLOT(on_CH20_stateChanged()));
    sendTimer = new QTimer(this);
    connect(sendTimer, SIGNAL(timeout()), this, SLOT(on_period_sends()));
    selchx[0]=1;
    selchx[1]=1;
    rcvmaxsize = 256;
    recvconvf = false;
    for(int i =2;i<20;i++)
        selchx[i] = 0;

    QList<QSerialPortInfo> strlist=QSerialPortInfo::availablePorts();
    QList<QSerialPortInfo>::const_iterator iter;
    for(iter=strlist.constBegin();iter!=strlist.constEnd();++iter)
    {
        ui->cb_SerialPort->addItem((*iter).portName());
    }
    ui->cb_SerialPort->addItems(netstring);
    //ui->cb_SerialPort->addItem("TCP Server");
    //ui->cb_SerialPort->addItem("TCP Client");
    //ui->cb_SerialPort->addItem("UDP Server");
    //ui->cb_SerialPort->addItem("UDP Client");
    chartSta=false;
    m_chart = new QChart;
    ui->chartView->setChart(m_chart);
    ui->chartView->setRubberBand(QChartView::RectangleRubberBand);
    ui->chartView->setRenderHint(QPainter::Antialiasing);

    //设置坐标系
    axisX = new QValueAxis;
    axisX->setRange(Xmin,Xmax);
    axisX->setLabelFormat("%g");
    axisX->setTickCount(11);
    //axisX->setTitleText("X轴");
    axisY = new QValueAxis;
    axisY->setRange(Ymin,Ymax);
    axisY->setTickCount(11);
    //axisY->setTitleText("Y轴");

    for(int i=0;i<Channel_number;++i)
    {
        m_series[i].setPen(QPen(QBrush(color[i]), 2));//设置线条颜色和粗细
        m_series[i].setName(QString("CH")+QString::number(i));
        m_chart->addSeries(&m_series[i]);
        m_chart->setAxisX(axisX,&m_series[i]);
        m_chart->setAxisY(axisY,&m_series[i]);
        m_series[i].setUseOpenGL(true);//openGl 加速
    }

    m_chart->legend()->setLabelColor(QColor(0,0,0));
    m_chart->legend()->setAlignment(Qt::AlignRight);
    m_chart->legend()->setContentsMargins(0,0,0,0);
    m_chart->legend()->setMarkerShape(QLegend::MarkerShapeCircle);
    //m_chart->legend()->hide();
    //m_chart->setTitle("串口示波器--基于QT");

    ui->statusBar->setContentsMargins(8,0,0,0);

    lb_StatusBar_SerialStatus = new QLabel;
    lb_StatusBar_SerialStatus->setText("串口状态：已关闭");
    ui->statusBar->insertWidget(0,lb_StatusBar_SerialStatus,1);

    lb_StatusBar_DataRecNum = new QLabel;
    lb_StatusBar_DataRecNum->setText(QString("已接收字节：%1").arg(dataRecNum));//修改状态栏
    ui->statusBar->insertWidget(1,lb_StatusBar_DataRecNum,1);

    ui->leXSize->setValidator(new QIntValidator(0, 99999, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readData()
{
    QByteArray arr;

    if(commethflag == 0)
        arr = port->readAll();
    else if(commethflag == 1)
        arr = socket->readAll();
    else if(commethflag == 2)
    {
        //arr = uSocket->readAll();
        arr.resize(uSocket->pendingDatagramSize());
        uSocket->readDatagram(arr.data(), arr.size(),&udpfromhost,&udpfromport);

        ui->Connect_ADDR->setText(udpfromhost.toString()+":"+QString::number(udpfromport));
               // std::cout << ba.data() << std::endl;
        //tempaddr = uSocket->peerAddress().toString();
    }
    else if(commethflag == 3)
    {
        arr = TCPCSocket->readAll();
    }

    hex2string(arr);
    dataRecNum+=arr.size();
    lb_StatusBar_DataRecNum->setText(QString("已接收字节：%1").arg(dataRecNum));//修改状态栏
//    if(ui->RCVAREA->toPlainText().count()>=2048)
//    {
//        //displaystr.clear();
//        //ui->RCVAREA->toPlainText().right(ui->RCVAREA->toPlainText().count());
//        uint16_t temp1 = ui->RCVAREA->toPlainText().count();
//        uint16_t temp2 = recvbuff.size();
//        ui->RCVAREA->append(recvbuff);
//        //ui->RCVAREA->insertPlainText(ui->RCVAREA->toPlainText().right(temp1-temp2));
//        //ui->RCVAREA->append(recvbuff);
//        //displaystr=displaystr.right(recvbuff.length());
//    }
//    else
//    {
//        ui->RCVAREA->insertPlainText(recvbuff);
//        //displaystr=displaystr.left(displaystr.length());
//    }
    ui->RCVAREA->append(recvbuff);
    //ui->RCVAREA->moveCursor(QTextCursor::End);
    //ui->RCVAREA->textCursor().movePosition(QTextCursor::End);
    //ui->RCVAREA->textCursor().deletePreviousChar();

//    ui->plainTextEdit->appendPlainText(recvbuff);
//    ui->plainTextEdit->textCursor().movePosition(QTextCursor::End);
//    ui->plainTextEdit->textCursor().deletePreviousChar();

    bool changed=false;//是否变动了points
    int32_t rec_data[16];
    uint16_t dcount = 0;
    processor.add(arr);//通讯协议processor添加数据

    //通讯成功&正在更新，持续添加点直至所有数据被添加到曲线
    while(processor.process((char *)rec_data,&dcount)&&chartSta==true)
    {
        //uint16_t dsize = sizeof((char *)rec_data);
        Xmax++;
        if(Xmax>XSize)//调节X轴（窗口）显示范围
            Xmin=Xmax-XSize;

        for(int i=0;i<dcount;i++)//接收到的数据为float型，每个数据4字节故/4
        {
           if(selchx[i])
                m_series[i].append(QPointF(Xmax,rec_data[i]));
        }
        changed = true;
    }
    if(changed)//变动了points，重新计算曲线最大最小值
    {
        Ymin=3.4028235e38f;
        Ymax=1.4e-45f;
        for(int i=0;i<Channel_number;i++)
        {
           //数据量超过窗口长度
           int pointssize=m_series[i].pointsVector().size();
           if(pointssize>XSize)
           {
               for(int j=pointssize-XSize;j<pointssize;j++)
               {
                   if(m_series[i].pointsVector().at(j).y()>Ymax)
                       Ymax=m_series[i].pointsVector().at(j).y();
                   if(m_series[i].pointsVector().at(j).y()<Ymin)
                       Ymin=m_series[i].pointsVector().at(j).y();
               }
           }
           else//数据量不足窗口长度
           {
               for(int j=0;j<pointssize;j++)
               {
                   if(m_series[i].pointsVector().at(j).y()>Ymax)
                       Ymax=m_series[i].pointsVector().at(j).y();
                   if(m_series[i].pointsVector().at(j).y()<Ymin)
                       Ymin=m_series[i].pointsVector().at(j).y();
               }
           }
        }
        //重新设置坐标轴（窗口）显示范围
        if(ui->checkBoxXAuto->isChecked())
            axisX->setRange(Xmin,Xmax);
        if(ui->checkBoxYAuto->isChecked())
            axisY->setRange(Ymin,Ymax);
    }
}

//void MainWindow::dispformat(QString appendStr)
//{
//      bool atEnd = ui->RCVAREA->size().height() >= 120;
//      QTextCharFormat fmt;
//     // QScrollBar* pqscfmt;

//     //fmt.setForeground(color);

//       QTextCursor tmp(ui->RCVAREA->document());

//       tmp.beginEditBlock();
//       tmp.movePosition(QTextCursor::End);

//       if (!ui->RCVAREA->document()->isEmpty())
//       {
//           tmp.insertBlock(ui->RCVAREA->textCursor().blockFormat(), ui->RCVAREA->textCursor().charFormat());
//       }else{

//           tmp.setCharFormat(ui->RCVAREA->textCursor().charFormat());
//       }

//       tmp.movePosition(QTextCursor::End);
//       tmp.deletePreviousChar();

//       tmp.insertText(appendStr, fmt);

//       // preserve the char format
//       QTextCharFormat oldCharFormat = ui->RCVAREA->textCursor().charFormat();

//       if (!ui->RCVAREA->textCursor().hasSelection())
//           ui->RCVAREA->textCursor().setCharFormat(oldCharFormat);

//       tmp.endEditBlock();
//       //if(atEnd)
//        //   ui->RCVAREA->verticalScrollBar();
//}

void MainWindow::server_New_Connect()
{
    //获取客户端连接
    socket = server->nextPendingConnection();
    tcpClient.append(socket);
    //连接QTcpSocket的信号槽，以读取新数据
    connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(socket_Disconnected()));
    //发送按键使能
    //ui->pushButton_Send->setEnabled(true);

    qDebug() << "A Client connect!";
}


void MainWindow::socket_Disconnected()
{
    //发送按键失能
    //ui->pushButton_Send->setEnabled(false);
    for(int i=0; i<tcpClient.length(); i++)
        {
            if(tcpClient[i]->state() == QAbstractSocket::UnconnectedState)
            {
                // 删除存储在combox中的客户端信息
                // 删除存储在tcpClient列表中的客户端信息
                 tcpClient[i]->destroyed();
                 tcpClient.removeAt(i);
            }
        }
    qDebug() << "Disconnected!";
}


void MainWindow::on_btn_OpenSerial_clicked()
{
    if(SerialSta)
    {
        if(commethflag == 0)
        {
            port->close();
            lb_StatusBar_SerialStatus->setText("串口状态：已关闭");
            ui->btn_OpenSerial->setText("打开串口");
            SerialSta=false;
        }
        else if(commethflag == 1)
        {
            for(int i=0; i<tcpClient.length(); i++)//断开所有连接
            {
               tcpClient[i]->disconnectFromHost();
//             bool ok = tcpClient[i]->waitForDisconnected(1000);
//             if(!ok)
//             {
//                         // 处理异常
//             }
               tcpClient.removeAt(i);  //从保存的客户端列表中取去除
         }
         server->close();     //不再监听端口
             //修改按键文字
         lb_StatusBar_SerialStatus->setText("侦听状态：关闭");
         ui->btn_OpenSerial->setText("开始侦听");
         SerialSta=false;
        }
        else if(commethflag == 2)
        {
            uSocket->close();//->close();     //不再监听端口
                //修改按键文字
            lb_StatusBar_SerialStatus->setText("绑定状态：关闭");
            ui->btn_OpenSerial->setText("开启绑定");
            SerialSta=false;
        }
        else if(commethflag == 3)
        {
            TCPCSocket->close();//->close();     //不再监听端口
                //修改按键文字
            lb_StatusBar_SerialStatus->setText("连接状态：关闭");
            ui->btn_OpenSerial->setText("开启连接");
            SerialSta=false;
        }
    }
    else
    {
#ifdef Q_OS_WIN
        QString commeth = ui->cb_SerialPort->currentText();
        if(commeth=="TCP Server")// || commeth=="TCP Client" || commeth=="UDP Server" || commeth=="UDP Client")
        {
            commethflag = 1;
            server = new QTcpServer();
            connect(server,SIGNAL(newConnection()),this,SLOT(server_New_Connect()));
        }
        else if(commeth == "UDP")
        {
            commethflag = 2;
            uSocket = new QUdpSocket();
            //uSocket->bind(QHostAddress(QHostAddress::Any), port);
        }
        else if(commeth == "TCP Client")
        {
            TCPCSocket = NULL;

                //分配空间，指定父对象
            TCPCSocket = new QTcpSocket(this);
                    //连接服务器
            commethflag = 3;
        }
//        else if(commeth == "UDP Client")
//        {
//            commethflag = 4;
//        }
        else
        {
            commethflag = 0;
            port->setPortName(commeth);
        }
#else
        port->setPortName("/dev/"+ui->cb_SerialPort->currentText());
#endif
        if(commethflag == 0)
        {
            port->setBaudRate(ui->cb_baudRate->currentText().toInt());
            port->setDataBits(QSerialPort::Data8);
            if(port->open(QIODevice::ReadWrite))
            {
                processor.clear();
                lb_StatusBar_SerialStatus->setText("串口状态：已开启");
                ui->btn_OpenSerial->setText("关闭串口");
                //ui->labelstatu->setStyleSheet("border-image: url(:/new/img/lv.png);");
                SerialSta=true;
            }
            else
            {
                SerialSta=false;
                QMessageBox::information(this,"提示","串口打开失败",QMessageBox::Ok);
                //ui->labelstatu->setStyleSheet("border-image: url(:/new/img/red.png);");
            }
        }
        else if(commethflag == 1)
        {
            int port = ui->cb_baudRate->currentText().toInt();
            //监听指定的端口
            if(!server->listen(QHostAddress::Any, port))
            {
                //若出错，则输出错误信息
                SerialSta=false;
                QMessageBox::information(this,"提示","侦听失败",QMessageBox::Ok);
                qDebug()<<server->errorString();
                //return;
            }
            else
            {
                processor.clear();
                lb_StatusBar_SerialStatus->setText("侦听状态：已开启");
                ui->btn_OpenSerial->setText("关闭侦听");
                qDebug()<< "Listen succeessfully!";
                SerialSta=true;
            }
        }
        else if(commethflag == 2)
        {
            int port = ui->cb_baudRate->currentText().toInt();
            if(!uSocket->bind(QHostAddress(ipAddr),port))
            {
                SerialSta=false;
                QMessageBox::information(this,"提示","绑定失败",QMessageBox::Ok);
                qDebug()<<server->errorString();
            }
            else
            {
                processor.clear();
                lb_StatusBar_SerialStatus->setText("绑定状态：已完成");
                ui->btn_OpenSerial->setText("关闭绑定");
                qDebug()<< "Bind Succeessfully!";
                SerialSta=true;

                connect(uSocket, SIGNAL(readyRead()), this, SLOT(readData()));
            }
                    //server->listen()
        }
        else if(commethflag == 3)
        {
            int port = ui->cb_baudRate->currentText().toInt();
            //if(!connect(TCPCSocket,))
            QString ip_s = ui->Connect_ADDR->text();
            if(port == 0)
            {
                QMessageBox::information(this, "PORT", "请输入端口！");
                return;
            }
            if(ip_s.isEmpty()||ip_s == "Enter IP ADDRESS")
            {
                QMessageBox::information(this, "IP", "请输入IP地址！");
                return;
            }
            TCPCSocket->connectToHost(ip_s, port);
            if(!TCPCSocket->waitForConnected(30000))
            {
                SerialSta=false;
                QMessageBox::information(this, "QT网络通信", "连接服务端失败！");
                //return;
            }
            else
            {
                processor.clear();
                lb_StatusBar_SerialStatus->setText("连接状态：已连接");
                ui->btn_OpenSerial->setText("关闭连接");
                qDebug()<< "Connect Succeessfully!";
                SerialSta=true;

                connect(TCPCSocket, SIGNAL(readyRead()), this, SLOT(readData()));
            }
        }
    }
}

void MainWindow::on_btn_help_clicked()
{
    QString strtext="1.串口通讯格式：1起始位，1停止位，8数据位，无校验位。\n"
                    "2.通信协议结构：帧头\\AA AA\\ + 功能码\\F1\\ + 数据字节数\(0-255)例如03 +用户数据\\例如：01 02 03\\ + 校验和\\校验范围为整个帧\n";

    QMessageBox::information(this, "帮助信息", strtext, QMessageBox::Ok);
}

void MainWindow::on_btn_StopDis_clicked()
{
    if(chartSta==false)
    {
        processor.clear();
        chartSta=true;
        ui->btn_StopDis->setText("暂停更新");
    }
    else
    {
        chartSta=false;
        ui->btn_StopDis->setText("开始更新");
    }
}

void MainWindow::on_action_save_triggered()
{
    QString filename;
    filename = QFileDialog::getSaveFileName(this,tr("保存文件"),"",tr("text(*.csv)"));
    if(filename.isEmpty())
        return;
    QFile file(filename);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("Error"),tr("Read file error:%1!").arg(file.errorString()));
        return ;
    }

    QTextStream write(&file);
    write<<writeDataToCSV();
    file.close();

}

void MainWindow::on_action_load_triggered()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this,tr("载入文件"),"",tr("text(*.csv)"));
    if(filename.isEmpty())
        return;
    QFile file(filename);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("Error"),tr("Read file error:%1!").arg(file.errorString()));
        return ;
    }

    QTextStream read(&file);
    readDataFromCSV(read);
    file.close();
}

QString MainWindow::writeDataToCSV()
{
    for(int i=0;i<Channel_number;i++)//得到当前曲线points
    {
       points[i] = m_series[i].pointsVector();
    }
    QString sDataStr;
    for(int i=0;i<Channel_number;i++)//得到当前曲线points
    {
       sDataStr.append(QString("CH%1:").arg(i));
       QVector<QPointF>::iterator iter;
       for(iter=points[i].begin();iter!=points[i].end();iter++)
       {
         sDataStr.append(QString(",%1").arg(iter->y()));
       }
       sDataStr.append("\n");
    }

    return sDataStr;
}
//此函数代码来自SACsvStream
int advplain(const QString &s, QString &fld, int i)
{
    int j;
    j = s.indexOf(',', i); // 查找,
    if (j < 0) // 没找到
        j = s.length();
    fld = s.mid (i,j-i);//提取内容
    return j;
}
//此函数中部分代码来自SACsvStream
void MainWindow::readDataFromCSV(QTextStream &sDataStream)
{

    QString sline[10];
    QString tempValue;
    int mmax=0;
    float ymin=3.4028235e38f;
    float ymax=1.4e-45f;
    for(int i=0;i<Channel_number;i++)//得到当前曲线points
    {
        int xmax=0;
        points[i].clear();
        sline[i]=sDataStream.readLine();
        if(sline[i].size()<6)
            continue;
        sline[i]=sline[i].mid(5);
        int k=0, j=0;
        do {
            j = advplain(sline[i], tempValue, k);
            points[i].append(QPointF(xmax++,tempValue.toDouble()));
            if(tempValue.toFloat()>ymax)
                ymax=tempValue.toFloat();
            if(tempValue.toFloat()<ymin)
                ymin=tempValue.toFloat();
            tempValue.clear();
            k = j + 1;
        } while (j < sline[i].length());
        if(xmax>mmax)
            mmax=xmax;
    }
    for(int i=0;i<Channel_number;i++)
    {
       m_series[i].replace(points[i]);
    }
    Xmax=mmax;
    if(mmax>200)
        Xmin=mmax-200;
    else
        Xmin=0;
    axisX->setRange(0,mmax);
    axisY->setRange(ymin,ymax);
}

void MainWindow::on_btn_ClearSeries_clicked()
{
    for(int i=0;i<Channel_number;i++)
    {
       points[i].clear();
       m_series[i].replace(points[i]);
    }
    Xmin=0;
    Xmax=0;
    Ymin=3.4028235e38f;
    Ymax=1.4e-45f;
    axisX->setRange(0,1);
    axisY->setRange(0,1);
}

void MainWindow::on_btn_SetXSize_clicked()
{
    //int xsize=0;
    XSize=ui->leXSize->text().toInt();

}

void MainWindow::on_CH1_stateChanged()
{
    if(ui->CH1->isChecked())
        {
            selchx[0] = 1;
            //ui->CH1->setEnabled(true);
        }
        else
        {
            selchx[0] = 0;
            //ui->CH1->setEnabled(false);
        }
}

void MainWindow::on_CH2_stateChanged()
{
    if(ui->CH2->isChecked())
        {
//            ui->CH2->setEnabled(true);
        selchx[1] = 1;
        }
        else
        {
            //ui->CH2->setEnabled(false);
        selchx[1] = 0;
        }
}
void MainWindow::on_CH3_stateChanged()
{
    if(ui->CH3->isChecked())
        {
            //ui->CH3->setEnabled(true);
            selchx[2] = 1;
        }
        else
        {
            //ui->CH3->setEnabled(false);
            selchx[2] = 0;
        }
}
void MainWindow::on_CH4_stateChanged()
{
    if(ui->CH4->isChecked())
        {
            //ui->CH4->setEnabled(true);
            selchx[3] = 1;
        }
        else
        {
            //ui->CH4->setEnabled(false);
            selchx[3] = 0;
        }
}
void MainWindow::on_CH5_stateChanged()
{
    if(ui->CH5->isChecked())
        {
           // ui->CH5->setEnabled(true);
            selchx[4] = 1;
        }
        else
        {
           // ui->CH5->setEnabled(false);
            selchx[4] = 0;
        }
}
void MainWindow::on_CH6_stateChanged()
{
    if(ui->CH6->isChecked())
        {
            //ui->CH6->setEnabled(true);
            selchx[5] = 1;
        }
        else
        {
            //ui->CH6->setEnabled(false);
            selchx[5] = 0;
        }
}
void MainWindow::on_CH7_stateChanged()
{
    if(ui->CH7->isChecked())
        {
            //ui->CH7->setEnabled(true);
            selchx[6] = 1;
        }
        else
        {
            //ui->CH7->setEnabled(false);
            selchx[6] = 0;
        }
}
void MainWindow::on_CH8_stateChanged()
{
    if(ui->CH8->isChecked())
        {
            //ui->CH8->setEnabled(true);
            selchx[7] = 1;
        }
        else
        {
            //ui->CH8->setEnabled(false);
            selchx[7] = 0;
        }
}
void MainWindow::on_CH9_stateChanged()
{
    if(ui->CH9->isChecked())
        {
            //ui->CH9->setEnabled(true);
            selchx[8] = 1;
        }
        else
        {
            //ui->CH9->setEnabled(false);
            selchx[8] = 0;
        }
}
void MainWindow::on_CH10_stateChanged()
{
    if(ui->CH10->isChecked())
        {
            //ui->CH10->setEnabled(true);
            selchx[9] = 1;
        }
        else
        {
           // ui->CH10->setEnabled(false);
            selchx[9] = 0;
        }
}
void MainWindow::on_CH11_stateChanged()
{
    if(ui->CH11->isChecked())
        {
            //ui->CH11->setEnabled(true);
            selchx[10] = 1;
        }
        else
        {
            //ui->CH11->setEnabled(false);
            selchx[10] = 0;
        }
}
void MainWindow::on_CH12_stateChanged()
{
    if(ui->CH12->isChecked())
        {
            //ui->CH12->setEnabled(true);
            selchx[11] = 1;
        }
        else
        {
            //ui->CH12->setEnabled(false);
            selchx[11] = 0;
        }
}
void MainWindow::on_CH13_stateChanged()
{
    if(ui->CH13->isChecked())
        {
            //ui->CH13->setEnabled(true);
            selchx[12] = 1;
        }
        else
        {
            //ui->CH13->setEnabled(false);
            selchx[12] = 0;
        }
}
void MainWindow::on_CH14_stateChanged()
{
    if(ui->CH14->isChecked())
        {
            //ui->CH14->setEnabled(true);
            selchx[13] = 1;
        }
        else
        {
            //ui->CH14->setEnabled(false);
            selchx[13] = 0;
        }
}
void MainWindow::on_CH15_stateChanged()
{
    if(ui->CH15->isChecked())
        {
            //ui->CH15->setEnabled(true);
            selchx[14] = 1;
        }
        else
        {
            //ui->CH15->setEnabled(false);
            selchx[14] = 0;
        }
}
void MainWindow::on_CH16_stateChanged()
{
    if(ui->CH16->isChecked())
        {
            //ui->CH16->setEnabled(true);
            selchx[15] = 1;
        }
        else
        {
            //ui->CH16->setEnabled(false);
            selchx[15] = 0;
        }
}
void MainWindow::on_CH17_stateChanged()
{
    if(ui->CH17->isChecked())
        {
            //ui->CH17->setEnabled(true);
            selchx[16] = 1;
        }
        else
        {
            //ui->CH17->setEnabled(false);
            selchx[16] = 0;
        }
}
void MainWindow::on_CH18_stateChanged()
{
    if(ui->CH18->isChecked())
        {
            //ui->CH18->setEnabled(true);
            selchx[17] = 1;
        }
        else
        {
            //ui->CH18->setEnabled(false);
            selchx[17] = 0;
        }
}
void MainWindow::on_CH19_stateChanged()
{
    if(ui->CH19->isChecked())
        {
            //ui->CH19->setEnabled(true);
            selchx[18] = 1;
        }
        else
        {
            //ui->CH19->setEnabled(false);
            selchx[18] = 0;
        }
}
void MainWindow::on_CH20_stateChanged()
{
    if(ui->CH20->isChecked())
        {
            //ui->CH20->setEnabled(true);
            selchx[19] = 1;
        }
        else
        {
            //ui->CH20->setEnabled(false);
            selchx[19] = 0;
        }
}


void MainWindow::hex2string(QByteArray &rcvstring)
{

    recvbuff.remove(0,recvbuff.size());

    if(ui->HEXRCV->isChecked())
    {
        for(int i = 0;i<rcvstring.size();i++)
        {
               uchar tempc = (uint8_t)(rcvstring.at(i))/16+(((uint8_t)(rcvstring.at(i))/16)<10?'0':('A'-10));
               recvbuff.append(tempc);
               tempc = (uint8_t)(rcvstring.at(i))%16+(((uint8_t)(rcvstring.at(i))%16)<10?'0':('A'-10));
               recvbuff.append(tempc);
               recvbuff.append(' ');
        }
    }
    else
        recvbuff = rcvstring;
    recvconvf = true;
}

void MainWindow::string2hex(QByteArray sendcoms)
{
    uint8_t hexhi=0,hexlo=0;
    uint16_t j=0;
    sendbuff.remove(0, sendbuff.size());
    if(ui->HEXSND->isChecked())
    {
        for(int i = 0;i<sendcoms.size();i++)
        {
            if(sendcoms.at(i)!= ' ')
            {

               if(sendcoms.at(i)>='0'&&sendcoms.at(i)<='9')
               {
                   if(j%2==0)
                       hexhi = sendcoms.at(i)-'0';
                   else if(j%2==1)
                   {
                       hexlo = sendcoms.at(i)-'0';
                       sendbuff.append((hexhi<<4)+hexlo);
                   }
               }
               else if(sendcoms.at(i)=='A'||sendcoms.at(i)=='B'||sendcoms.at(i)=='C'||sendcoms.at(i)=='D'||sendcoms.at(i)=='E'||sendcoms.at(i)=='F')
               {
                   if(j%2==0)
                       hexhi = sendcoms.at(i)-'A'+10;
                   else if(j%2==1)
                   {
                       hexlo = sendcoms.at(i)-'A'+10;
                       sendbuff.append((hexhi<<4)+hexlo);
                   }

               }
               else if(sendcoms.at(i)=='a'||sendcoms.at(i)=='b'||sendcoms.at(i)=='c'||sendcoms.at(i)=='d'||sendcoms.at(i)=='e'||sendcoms.at(i)=='f')
               {
                   if(j%2==0)
                       hexhi = sendcoms.at(i)-'a'+10;
                   else if(j%2==1)
                   {
                       hexlo = sendcoms.at(i)-'a'+10;
                        sendbuff.append((hexhi<<4)+hexlo);
                   }
               }
               else if(sendcoms.at(i)=='\n')
               {
                   continue;
               }
               else
               {
                   //QMessageBox::warning(NULL, "warning", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                   qDebug()<<"NO";
                   return;
               }
               j++;

            }
            else
            {

                 continue;
            }

        }


    }
    else
        sendbuff = sendcoms;
}

void MainWindow::writeData(char* data,unsigned int len)
{
    //port->write(data,len);

    if(commethflag == 0)
        port->write(data,len);
    else if(commethflag == 1)
        socket->write(data,len);
    else if(commethflag == 2)
    {
        QString tempstrip = ui->Connect_ADDR->text();
        QStringList ipport = (ui->Connect_ADDR->text()).split(":");
        QHostAddress  address(ipport.at(0));
        quint16 udpport = (ipport.at(1)).toUInt();
        uSocket->writeDatagram(QByteArray(data,len),address,udpport);
    }
    else if(commethflag == 3)
    {
        TCPCSocket->write(data,len);
    }
}

void MainWindow::on_BTNSEND_clicked()
{
    QByteArray sendcomstxt = (ui->sendmulcom->toPlainText()).toLatin1();
    QByteArray senddata;
    //uint16_t len =0;

    string2hex(sendcomstxt);
    senddata = sendbuff;

    //len = senddata.size();

    writeData(senddata.data(),senddata.size());
}

void MainWindow::on_period_sends()
{
    QByteArray sendcomstxt = (ui->sendmulcom->toPlainText()).toLatin1();
    QByteArray senddata;
    //uint16_t len =0;

    string2hex(sendcomstxt);
    senddata = sendbuff;

    //len = senddata.size();

    writeData(senddata.data(),senddata.size());
}

void MainWindow::on_HEXSND_stateChanged()
{
    QByteArray sendcomstxt = (ui->sendmulcom->toPlainText()).toLatin1();
    //unsigned char hexcode[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string2hex(sendcomstxt);
}

void MainWindow::on_pushButton_clicked()
{
    QByteArray sendcomstxt = (ui->lineEdit_17->text()).toLatin1();
    QByteArray senddata;
    //uint16_t len =0;

    string2hex(sendcomstxt);
    senddata = sendbuff;

    //len = senddata.size();

    writeData(senddata.data(),senddata.size());
}

void MainWindow::on_pushButton_2_clicked()
{
    QByteArray sendcomstxt = (ui->lineEdit_18->text()).toLatin1();
    QByteArray senddata;
    //uint16_t len =0;

    string2hex(sendcomstxt);
    senddata = sendbuff;

    //len = senddata.size();

    writeData(senddata.data(),senddata.size());
}

void MainWindow::on_pushButton_3_clicked()
{
    QByteArray sendcomstxt = (ui->lineEdit_19->text()).toLatin1();
    QByteArray senddata;
    //uint16_t len =0;

    string2hex(sendcomstxt);
    senddata = sendbuff;

    //len = senddata.size();

    writeData(senddata.data(),senddata.size());
}

void MainWindow::on_pushButton_4_clicked()
{
    QByteArray sendcomstxt = (ui->lineEdit_20->text()).toLatin1();
    QByteArray senddata;
    //uint16_t len =0;

    string2hex(sendcomstxt);
    senddata = sendbuff;

    //len = senddata.size();

    writeData(senddata.data(),senddata.size());
}

void MainWindow::on_pushButton_5_clicked()
{
    QByteArray sendcomstxt = (ui->lineEdit_21->text()).toLatin1();
    QByteArray senddata;
    //uint16_t len =0;

    string2hex(sendcomstxt);
    senddata = sendbuff;

    //len = senddata.size();

    writeData(senddata.data(),senddata.size());
}

void MainWindow::on_pushButton_6_clicked()
{
    QByteArray sendcomstxt = (ui->lineEdit_22->text()).toLatin1();
    QByteArray senddata;
    //uint16_t len =0;

    string2hex(sendcomstxt);
    senddata = sendbuff;

    //len = senddata.size();

    writeData(senddata.data(),senddata.size());
}

void MainWindow::on_periodsend_stateChanged()
{
    QString timestr = ui->lineEdit_16->text();

    uint timevalue;

    if(timestr.isEmpty())
    {
        QMessageBox::warning(NULL, "warning", "timer is empty", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        qDebug()<<"timer is empty!!";
        return;
    }
    else
    {
        timevalue = (ui->lineEdit_16->text()).toUInt();
    }
    if(ui->periodsend->isChecked())
    {
        if (sendTimer->isActive() == false)
        {
             sendTimer->start(timevalue);
        }
    }
    else
    {

        if (sendTimer->isActive() == true)
        {
             sendTimer->stop();
        }
    }
}

void MainWindow::on_cb_SerialPort_activated()
{
    QString commeth = ui->cb_SerialPort->currentText();
    //port->setPortName(commeth);
    if(commeth=="TCP Server")// || commeth=="TCP Client" || commeth=="UDP")
    {
        lb_StatusBar_SerialStatus->setText("侦听状态：关闭");
        ui->btn_OpenSerial->setText("开始侦听");
        ui->cb_baudRate->clear();
        ui->Connect_ADDR->setDisabled(true);
        bditemf = 0;
    }
    else if(commeth=="TCP Client")
    {
        lb_StatusBar_SerialStatus->setText("绑定状态：关闭");
        ui->btn_OpenSerial->setText("开启绑定");
        ui->cb_baudRate->clear();
        ui->Connect_ADDR->setEnabled(true);
        ui->Connect_ADDR->setText("Enter IP ADDRESS");
        ui->Connect_ADDR->setStatusTip("Enter IP ADDRESS");
        bditemf = 0;
    }
    else if(commeth=="UDP")
    {
        lb_StatusBar_SerialStatus->setText("绑定状态：关闭");
        ui->btn_OpenSerial->setText("开启绑定");
        ui->cb_baudRate->clear();
        ui->Connect_ADDR->setEnabled(true);
        bditemf = 0;
    }
    else
    {
        lb_StatusBar_SerialStatus->setText("串口状态：已关闭");
        ui->btn_OpenSerial->setText("打开串口");
        if(!bditemf)
            ui->cb_baudRate->addItems(baudspeed);
        ui->Connect_ADDR->setDisabled(true);
        bditemf = 1;
    }

}
