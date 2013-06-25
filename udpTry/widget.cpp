#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}


Widget::Widget(qint16 selfport,qint16 destinationport,QString destinationIP,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //initialize all the variable
    ui->setupUi(this);
    udpSocket=new QUdpSocket();
    port=selfport;
    destport=destinationport;
    destIP=destinationIP;
    this->setWindowTitle("My port is "+QString::number(port));
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));

}



Widget::~Widget()
{
    delete ui;
}


void Widget::processPendingDatagrams()
{
    QByteArray data;
    int size=udpSocket->pendingDatagramSize();
    data.resize(size);

    //read the data from udpsocket
    udpSocket->readDatagram(data.data(),size);
    destpoints.append(QString(data));
    update(0,0,this->width(),this->height());
}




void Widget::mousePressEvent(QMouseEvent *event)
{


    //get x and y co-ordinates of the mouse press event
    QString strx= QString::number(event->pos().x());
    QString stry= QString::number(event->pos().y());
    QString str=QString(strx+"="+stry);

    //update the data structure
    points.append(str);
    QByteArray n=str.toUtf8();

    //send data
    const QHostAddress destadd=QHostAddress(destIP);
    udpSocket->writeDatagram(n,destadd,destport);

    //update the board
    update();
}


void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    //iterate through the data structure and update the drawing board
    for(int i=0;i<(points.length()-1);i++){
        if( points.at(i+1)!="==="){
            data=points.at(i);
            pointlist=data.split("=");
            x=pointlist[0].toInt();
            y=pointlist[1].toInt();
            data=points.at(i+1);
            pointlist=data.split("=");
            p.drawLine(x,y,pointlist[0].toInt(),pointlist[1].toInt());
        }
        else{
            i++;
        }

    }


    for( int i=0;i<(destpoints.length()-1);i++){
        if( destpoints.at(i+1)!="==="){
            data=destpoints.at(i);
            pointlist=data.split("=");
            x=pointlist[0].toInt();
            y=pointlist[1].toInt();
            data=destpoints.at(i+1);
            pointlist=data.split("=");
            p.drawLine(x,y,pointlist[0].toInt(),pointlist[1].toInt());
        }
        else{
            i++;
        }

    }


}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    //get x and y co-ordinates of the mouse press event
    QString strx= QString::number(event->pos().x());
    QString stry= QString::number(event->pos().y());
    QString str=QString(strx+"="+stry);

    //update the data structure
    points.append(str);
    QByteArray n=str.toUtf8();

    //send data
    const QHostAddress destadd=QHostAddress(destIP);
    udpSocket->writeDatagram(n,destadd,destport);

    //update board
    update();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QString str=QString("===");
    points.append(str);
    QByteArray n=str.toUtf8();

    //send data
    const QHostAddress destadd=QHostAddress(destIP);
    udpSocket->writeDatagram(n,destadd,destport);

    //send data
    update();
}


bool Widget::bindport()
{
    return udpSocket->bind(QHostAddress::Any,this->port);
}



