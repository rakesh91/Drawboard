#ifndef HELPWIDGET_H
#define HELPWIDGET_H

#include <QWidget>

namespace Ui {
class helpwidget;
}

class helpwidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit helpwidget(QWidget *parent = 0);
    ~helpwidget();
    
private:
    Ui::helpwidget *ui;
};

#endif // HELPWIDGET_H
