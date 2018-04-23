#ifndef HASTA_H
#define HASTA_H

#include <QDialog>
#include <QTcpSocket>
#include<QDebug>
#include <QTcpServer>
#include<QTableWidget>


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

    void on_isimler_cellChanged(int row, int column);

    void on_isimler_itemSelectionChanged();

    void on_isimler_itemChanged(QTableWidgetItem *item);

    void on_isimler_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

private:
    QTcpServer *server;
    Ui::hasta *ui;
};

#endif // HASTA_H
