#ifndef WIDGET_H
#define WIDGET_H
// Подключаем основные библиотеки
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

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

// Класс счетчика, наследуемый от QLineEdit
class Counter:public QLineEdit
{
    Q_OBJECT
public:
    // Конструктор класса Counter, который принимает строку и указатель на родительский элемент
    Counter(const QString & contents, QWidget *parent=0):
        QLineEdit(contents,parent){
        // Определяем размер счетчика на основе размера его родительского элемента
        QSize sizeHint = parent->sizeHint();
        // Устанавливаем размер от родительского элемента
        setGeometry(0,0, parent->parentWidget()->width(), sizeHint.height());
    };
    ~Counter()
    {
        delete this;
    };

signals:
    // Сигнал, который будет отправлен при достижении числа, кратного 5
    void tick_signal();

public slots:
    // Слот, который будет вызываться при нажатии на кнопку "+1"
    void add_one()
    {
        // Получаем текущее значение счетчика
        QString str=text();
        int r=str.toInt();
        // Увеличиваем значение счетчика на 1
        r++;
        // Если число кратно 5, то отправляем сигнал tick_signal()
        if (r!=0 && r%5 ==0) emit tick_signal();
        // Преобразуем значение в строку и устанавливаем его в QLineEdit
        str.setNum(r);
        setText(str);
    }
};

#endif // WIDGET_H
