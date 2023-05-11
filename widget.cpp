// Подключение заголовочных файлов, объявление класса Widget
#include "widget.h"
#include "ui_widget.h"

// Конструктор класса Widget
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // Обработка исключения при неуспешном выделении памяти
    ui = new Ui::Widget;
    if (ui == nullptr)
    {throw std::bad_alloc();}
    // Инициализация пользовательского интерфейса
    ui->setupUi(this);

    Counter *edit1 = new Counter("0", ui->lineEdit);
    Counter *edit2 = new Counter("0", ui->countFive);
    if (edit1 == nullptr or edit2 == nullptr)
    {throw std::bad_alloc();}

    // Связь сигналов и слотов
    connect(ui->calcButton,SIGNAL(clicked()),
            edit1,SLOT(add_one()));
    connect(edit1,SIGNAL(tick_signal()),
            edit2,SLOT(add_one()));
    connect(ui->exitButton,SIGNAL(clicked()),
            this,SLOT(close()));
}

Widget::~Widget()
{
    // Освобождаем память, выделенную для ui
    delete ui;
}

