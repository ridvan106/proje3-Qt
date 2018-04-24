#include "hasta.h"
#include "ui_hasta.h"
#include "patients.cpp"
#include <QLineEdit>
#define COL  3


hasta::hasta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hasta)

{
   /* server = new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any,8081)){
       qDebug() <<"server could not start";
 }else{

     qDebug() <<"server start";
 }*/

    ui->setupUi(this);
    patients hastalar;

    QPixmap img1("/home/oem/untitled/icon.png");
    QPixmap img2("/home/oem/untitled/doctor.jpeg");
    QPixmap img3("/home/oem/untitled/nurse.jpeg");
    QPixmap img4("/home/oem/untitled/patient.jpeg");
    ui->icon->setPixmap(img1);
    ui->right_icon->setPixmap(img4);
    ui->isimler->setColumnCount(5);
    ui->isimler->setRowCount(--hastalar.patientsSize);
    ui->isimler->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QTableWidgetItem *h1 = new QTableWidgetItem("isim soyisim");
    QTableWidgetItem *h2 = new QTableWidgetItem("Kalp Değerleri");
    QTableWidgetItem *h3 = new QTableWidgetItem("Kan Değerleri");
    QTableWidgetItem *h4 = new QTableWidgetItem("Şeker Değerleri");
    ui->isimler->setHorizontalHeaderItem(0,h1);
    ui->isimler->setHorizontalHeaderItem(1,h2);
    ui->isimler->setHorizontalHeaderItem(2,h3);
    ui->isimler->setHorizontalHeaderItem(3,h4);
    for (int var = 0; var < hastalar.patientsSize; ++var) {
            QTableWidgetItem *isim = new QTableWidgetItem();
            //isim->setObjectName((QString) var );
            hastalar.getVeri(var+1);
            isim->setText(hastalar.getName()+ "  " + hastalar.getSurname());
            ui->isimler->setItem(var,0,isim);

                QTableWidgetItem *kalp = new QTableWidgetItem();
                QTableWidgetItem *seker = new QTableWidgetItem();
                QTableWidgetItem *kan = new QTableWidgetItem();
                QTableWidgetItem *gonder = new QTableWidgetItem("Gonder");


                kalp->setTextAlignment(5);//center yapar

                seker->setTextAlignment(5);
                kan->setTextAlignment(5);


                kalp->setText(hastalar.getHeart());
                ui->isimler->setItem(var,1,kalp);
                kan->setText(hastalar.getBlood());
                ui->isimler->setItem(var,2,kan);
                seker->setText(hastalar.getGlikoz());
                ui->isimler->setItem(var,3,seker);
                gonder->setTextAlignment(5);

                gonder->setText("Gonder");
                ui->isimler->setItem(var,4,gonder);


    }
    /*for (int var = 0; var < hastalar.patientsSize; ++var) {
        QLabel *isim = new QLabel(ui->isimler);
        hastalar.getVeri(var+1);
        isim->setText(hastalar.getName()+ "  " + hastalar.getSurname());
        ui->isimler->setCellWidget(var,0,isim);

            QLineEdit *kalp = new QLineEdit(ui->isimler);
            QLineEdit *seker = new QLineEdit(ui->isimler);
            QLineEdit *kan = new QLineEdit(ui->isimler);

            kalp->setText(hastalar.getHeart());
            ui->isimler->setCellWidget(var,1,kalp);
            kan->setText(hastalar.getBlood());
            ui->isimler->setCellWidget(var,2,kan);
            seker->setText(hastalar.getGlikoz());
            ui->isimler->setCellWidget(var,3,seker);


    }*/


}

hasta::~hasta()
{
    delete ui;
}

void hasta::on_pushButton_clicked()
{



}
void hasta::sendData(char data[]){
    QTcpSocket *tcpClient = new QTcpSocket(this);
   // connect( tcpClient, SIGNAL(readyRead()), NULL );
    tcpClient->connectToHost("192.168.43.166",8081);
    if( tcpClient->waitForConnected() ) {
         tcpClient->write(data);
          ui->icon->setText("send");
          tcpClient->close();
       }

    else{
         ui->icon->setText("temp");
    }




}
void hasta::newConnection(){


    socket = server->nextPendingConnection();
    qDebug() <<"yazildi";

    socket->write("hello ardunio");
    //data = socket->readLine();
    //ui->isim->setText(data);
    socket->close();
}



void hasta::on_isimler_cellClicked(int row, int column)
{
    QString temp = ui->isimler->item(row,column)->text();
      if(temp.compare("Gonder") == 0){

          ui->pushButton->setText(temp);
      }

      qDebug() <<temp;
}
