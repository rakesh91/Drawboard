#include "mainview.h"
#include "ui_mainview.h"

mainView::mainView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainView)
{
    ui->setupUi(this);
    connect(ui->connect,SIGNAL(clicked()),this,SLOT(connecttodest()));  //connect button click
    connect(ui->help,SIGNAL(clicked()),this,SLOT(helpView())); //help widget display
}

mainView::~mainView()
{
    delete ui;
}

void mainView::connecttodest()
{
    w=new Widget(ui->your_port->text().toInt(),ui->dest_port->text().toInt(),ui->dest_IP->text());
    w->setAttribute(Qt::WA_DeleteOnClose); // delete the object once closed

    //try to bind to specified port,if fails display in the UI
    if(w->bindport()){
        ui->error->setText("");
        w->show();
    }
    else{
        ui->error->setText("Port already in use");
        w->close();}
}

void mainView::helpView()
{
    helpwidget *hw=new helpwidget();
    hw->setAttribute(Qt::WA_DeleteOnClose);
    hw->show();
}
