#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Counter *edit1 = new Counter("0", ui->lineEdit);
    Counter *edit2 = new Counter("0", ui->countFive);

    // связь сигнала нажатия кнопки и слота закрытия окна
    connect(ui->calcButton,SIGNAL(clicked(bool)),
            edit1,SLOT(add_one()));
    connect(edit1,SIGNAL(tick_signal()),
            edit2,SLOT(add_one()));
    connect(ui->exitButton,SIGNAL(clicked(bool)),
            this,SLOT(close()));
}

Widget::~Widget()
{
    delete ui;
}

