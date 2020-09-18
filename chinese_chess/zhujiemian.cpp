#include "zhujiemian.h"
#include "ui_widget.h"
#include "board.h"
#include <QMessageBox>
#include <QPainter>
#include <SingleGame.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("中国象棋");
    setWindowIcon(QIcon("://image/download.jpg"));
    QFont font ("Microsoft YaHei",30,75);
    ui->biaoti->setFont(font);
    connect(ui->shuangren,&QPushButton::clicked,
            [=]()
    {
       h=new Board;
       h->show();
        this->hide();
    }
            );
    connect(ui->danren,&QPushButton::clicked,
            [=]()
    {
        h=new SingleGame;
        h->show();
        this->hide();
    }
            );
    connect(ui->tuichu,&QPushButton::clicked,
            [=]()
    {
        int ret=QMessageBox::question(this,"退出游戏","确定要退出游戏吗?",QMessageBox::Yes|QMessageBox::No);
        switch (ret)
        {
        case QMessageBox::Yes:
            this->close();
            break;
        case QMessageBox::No:
            break;
        default:
            break;
        }
    }
            );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p;
    p.begin(this);
    p.drawPixmap(rect(),QPixmap("://image/timg.jpg"));
    p.end();
}
