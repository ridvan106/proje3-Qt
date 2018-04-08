#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hasta.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

   /* server = new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    if(!server->listen(QHostAddress::Any,8081)){
       qDebug() <<"server not ok";
    }else{
        qDebug() <<"server ok";
    }*/

   // ui->isim->setText("<center>GELEN DEGER  </center>");

    /* Socket programming code above */
 ui->setupUi(this);
    QPixmap img1("/home/oem/untitled/icon.png");
    QPixmap img2("/home/oem/untitled/doctor.jpeg");
    QPixmap img3("/home/oem/untitled/nurse.jpeg");
    QPixmap img4("/home/oem/untitled/patient.jpeg");
    ui->icon->setPixmap(img1);
    ui->doktor->setPixmap(img2);
    ui->nurse->setPixmap(img3);


    ui->patient->setIcon(img4);
    ui->patient->setIconSize(img4.rect().size());

    //ui->patient->setFixedSize(img4.rect().size());
    //ui->patient->setIcon(img4);
   // ui->patient->setIconSize(QSize(250,250));
    //ui->patient->setPixmap(img4);
  //  ui->patient->setText("<img src:/home/oem/untitled/patient.jpeg />");


   // ui->title->setStyleSheet("width:100%;color:red;");
   // ui->title->setGeometry(MainWindow::x(),MainWindow::y(),MainWindow::maximumWidth(),150);
    //ui->label->resize(MainWindow::width(),150);
   // ui->label->setText("<table width=500px><tr><td>sdad </td></tr><tr><td> adasd</td></tr></table>");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buton_clicked()
{



}


void MainWindow::on_patient_linkActivated(const QString &link)
{

}
void MainWindow::newConnection(){


    /*QTcpSocket * socket = server->nextPendingConnection();
    qDebug() <<"yazildi";

    //socket->write("hello ardunio");
    //data = socket->readLine();
    //ui->isim->setText(data);
    socket->close();?*/

}
void MainWindow::on_patient_clicked()
{






    MainWindow::close();
    hasta hasta1;
    hasta1.setModal(true);
    hasta1.exec();

}

