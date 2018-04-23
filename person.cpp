#include<QString>
class Person
{
public:
    Person(): uniqueID("No ID defined."), name("No name defined."), surname("No surname defined.") { }
    Person(QString uniqueID, QString name, QString surname) : uniqueID(uniqueID), name(name), surname(surname) { }

    virtual QString getUniqueID() { return uniqueID; }
    virtual QString getName() { return name; }
    virtual QString getSurname() { return surname; }
    virtual void setUniqueID(QString uniqueID) { this->uniqueID = uniqueID; }
    virtual void setName(QString name) { this->name = name; }
    virtual void setSurname(QString surname) { this->surname = surname; }

private:
    QString uniqueID;
    QString name;
    QString surname;

};
