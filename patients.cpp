#include "qfile.h"
#include<QDebug>
#include "person.cpp"
class  patients : public Person
{
public:
    int patientsSize;
    patients(){
        patientsSize = 0;


        QFile file("/home/oem/Desktop/proje3-Qt/patients.csv");

        if(file.exists())
            qDebug() << "mevcut";
        else
            qDebug() << "degil";
        file.open(QIODevice::Truncate | QFile::ReadOnly);

           QTextStream yazi(&file);
           while(!yazi.atEnd()){
               QString temp = yazi.readLine();
               qDebug() <<temp;
               veriler.push_back(temp);
               patientsSize++;

           }
    }
    QString getVeri(int i){
        QString temp =veriler.at(i);
        QStringList piece = temp.split(',');
        setName(piece.at(1));
        setSurname(piece.at(2));
        setGlikoz(piece.at(7));
        setHeart(piece.at(5));
        setBlood(piece.at(6));
        return piece.at(7);

    }
    QString getHeart() const;
    void setHeart(const QString &value);

    QString getBlood() const;
    void setBlood(const QString &value);

    QString getGlikoz() const;
    void setGlikoz(const QString &value);

private:
    QVector<QString> veriler;
    QString heart;
    QString blood;
    QString glikoz;

};

QString patients::getHeart() const
{
return heart;
}

void patients::setHeart(const QString &value)
{
heart = value;
}

QString patients::getBlood() const
{
return blood;
}

void patients::setBlood(const QString &value)
{
blood = value;
}

QString patients::getGlikoz() const
{
return glikoz;
}

void patients::setGlikoz(const QString &value)
{
glikoz = value;
}
