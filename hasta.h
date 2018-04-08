#ifndef HASTA_H
#define HASTA_H

#include <QDialog>
#include <QTcpSocket>
#include<QDebug>
#include <QTcpServer>


namespace Ui {
class hasta;
}

class hasta : public QDialog
{
    Q_OBJECT

public:
     QTcpSocket * socket;
    explicit hasta(QWidget *parent = 0);
    void sendData(char *data);
    int clientPort;
    ~hasta();
signals:
    public slots:
     void newConnection();
private slots:

    void on_pushButton_clicked();

private:
    QTcpServer *server;
    Ui::hasta *ui;
};

#endif // HASTA_H
