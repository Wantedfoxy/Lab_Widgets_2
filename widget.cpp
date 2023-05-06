// Подключение заголовочных файлов, объявление класса Widget
#include "widget.h"
#include "ui_widget.h"

// Конструктор класса Widget
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    // Инициализация пользовательского интерфейса
    ui->setupUi(this);

    Counter *edit1 = new Counter("0", ui->lineEdit);
    Counter *edit2 = new Counter("0", ui->countFive);

    // Связь сигналов и слотов
    connect(ui->calcButton,SIGNAL(clicked(bool)),
            edit1,SLOT(add_one()));
    connect(edit1,SIGNAL(tick_signal()),
            edit2,SLOT(add_one()));
    connect(ui->exitButton,SIGNAL(clicked(bool)),
            this,SLOT(close()));
}

Widget::~Widget()
{
    // Освобождаем память, выделенную для ui
    delete ui;
}

