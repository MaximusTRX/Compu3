#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusbar->showMessage("Hola mundo...");

    ui->pushButton_2->setText("Cambiar a DESCENDENTE");
    ui->pushButton->setText("ON");

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
    if(QTimer1->isActive()){
        QTimer1->stop();
        ui->pushButton->setText("ON");
    }
    else {
        QTimer1->start(100);
        ui->pushButton->setText("OFF");
    }
}

void MainWindow::onQTimer1(){

    if(direction)
        counter--;
    else
        counter++;

    if(counter == 13)
        counter = 0;
    else if (counter == 0)
        counter = 13;

    ui->lineEdit->setText(QString("%1").arg(counter, 5, 10 , QChar('0'))); //arg(VariableAMostrar, LugaresReservados, formato, QChar('CharParaCompletar')); formato: 2(binario), 10(decimal), 16(hexa)
}

void MainWindow::on_pushButton_2_clicked()
{
    if(direction){
        direction = 0;
        ui->pushButton_2->setText("Cambiar a ASCENDENTE");
    }
    else {
        direction = 1;
        ui->pushButton_2->setText("Cambiar a DESCENDENTE");
    }
}
