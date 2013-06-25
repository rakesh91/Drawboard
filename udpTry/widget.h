#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork/QUdpSocket>
#include <QMoveEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QList>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    explicit Widget(qint16 selfport,qint16 destinationport,QString destinationIP,QWidget *parent = 0);
    ~Widget();
    QUdpSocket * udpSocket;  //udpSocket for the communication
    QList <QString  > points; //list which holds the points
    QList <QString  > destpoints;
    int x,y; //points for drawing
    QString data; //buffer data
    qint16 port; //port used in host system
    qint16 destport; //port to be connected in destination system
    QString destIP; //destination IP
    QStringList pointlist; //intermmediate data




public slots:
    void processPendingDatagrams(); //slot for the processing data


public:
    bool bindport(); //function bind the port

protected:
    void mousePressEvent(QMouseEvent * event); //slot for the mouse press event
    void paintEvent(QPaintEvent *event); //function for drawing
    void mouseMoveEvent(QMouseEvent *event); //slot for the mouse move event
    void mouseReleaseEvent(QMouseEvent *event);//slot for the mouse release event



private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
