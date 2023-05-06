#ifndef WIDGET_H
#define WIDGET_H
// Подключаем основные библиотеки
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    // Указатель на объект интерфейса
    Ui::Widget *ui;
};

class Counter:public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent=0):
        QLineEdit(contents,parent){
        QSize sizeHint = parent->sizeHint();
        setGeometry(0,0, parent->parentWidget()->width(), sizeHint.height());
    }
signals:
    void tick_signal();

public slots:
    void add_one()
    {
        QString str=text();
        int r=str.toInt();
        if (r!=0 && r%5 ==0) emit tick_signal();
        r++;
        str.setNum(r);
        setText(str);
    }
};

#endif // WIDGET_H
