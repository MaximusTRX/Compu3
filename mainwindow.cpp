#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer1 = new QTimer(this);
    connect(QTimer1, &QTimer::timeout, this, &MainWindow::onQTimer1);

    counter = 0;

}

MainWindow::~MainWindow()
{
    delete QTimer1;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    counter++;

    if(counter == 13)
        counter = 0;

    ui->pushButton_2->setText(QString().number(counter));
    ui->lineEdit->setText(QString("%1").arg(counter));
}

void MainWindow::onQTimer1(){

}

void MainWindow::on_pushButton_2_clicked()
{
    counter--;

    if(counter == 0)
        counter = 13;

    ui->pushButton_2->setText(QString().number(counter));
    ui->lineEdit->setText(QString("%1").arg(counter));
}

