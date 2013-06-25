#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include "widget.h"
#include "helpwidget.h"
namespace Ui {
class mainView;
}

class mainView : public QWidget
{
    Q_OBJECT
    
public:
    Widget *w;
    explicit mainView(QWidget *parent = 0);
    ~mainView();
    
private:
    Ui::mainView *ui;

private slots:
    void connecttodest();//for connect button click
    void helpView(); //view of help
};

#endif // MAINVIEW_H
