#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QObject>

#include<QDebug>
#include<QTcpServer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QTcpSocket * socket;
    void connects();
    explicit MainWindow(QWidget *parent = 0);
    void connectTcp();
    ~MainWindow();
signals:
    public slots:
     void newConnection();
private slots:
    void on_buton_clicked();


    void on_patient_linkActivated(const QString &link);

    void on_patient_clicked();

private:
    QTcpServer *server;
    bool name = true;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
