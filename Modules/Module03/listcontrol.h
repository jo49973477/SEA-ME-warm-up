#ifndef LISTCONTROL_H
#define LISTCONTROL_H

#include <QObject>
#include "QContactList.h"

class ListControl : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int len READ len NOTIFY listChanged)
    Q_PROPERTY(QString nowName READ nowName NOTIFY idxChanged)
    Q_PROPERTY(QString nowNumber READ nowNumber NOTIFY idxChanged)
    Q_PROPERTY(QString nowEmail READ nowEmail NOTIFY idxChanged)

protected:
    int index = -1;
    QContactList list;

public:
    explicit ListControl(QObject *parent = nullptr);
    ~ListControl();
    ListControl(const ListControl& control);
    ListControl& operator= (const ListControl& control);

    Q_INVOKABLE QContactList * getModel() {return &list;}
    Q_INVOKABLE void selectRow(int idx);
    Q_INVOKABLE void add(QString name, QString number, QString email);
    Q_INVOKABLE void edit(int idx, QString name, QString number, QString email);
    Q_INVOKABLE void remove(int idx);

    QString nowName();
    QString nowNumber();
    QString nowEmail();
    int len(){ return list.rowCount();}

    void debug();

signals:
    void idxChanged();
    void listChanged();

};

#endif // LISTCONTROL_H
