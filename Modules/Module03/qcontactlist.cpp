#include "qcontactlist.h"
#include <QAbstractListModel>

QContactList::QContactList(QObject *parent)
    : QAbstractListModel{parent}
{

}

QContactList::~QContactList(){}

QContactList::QContactList(const QContactList& qlist): QAbstractListModel(){
    this->list = qlist.list;
}

QContactList& QContactList::operator= (const QContactList& other){
    this->list = other.list;
    this->roleNames();
    return *this;
}

QHash<int, QByteArray> QContactList::roleNames() const{
    QHash<int, QByteArray> role;

    role[nName] = "name";
    role[nNumber] = "number";
    role[nEmail] = "email";

    return role;
}

int QContactList::rowCount(const QModelIndex &) const{
    return list.count();
}

QVariant QContactList::data(const QModelIndex &index, int nRole) const{
    int nRow = index.row();
    if (nRow < 0){
        return QVariant();
    }
    Contact contact = list.at(nRow);
    switch(nRole){
    case nName:
        return contact.showName();
    case nNumber:
        return contact.showNumber();
    case nEmail:
        return contact.showEmail();
    default:
        return QVariant();
    }
}

void QContactList::add(QString name, QString number, QString email){
    int len = rowCount();
    beginInsertRows(QModelIndex(), len, len);
    list.append(Contact(name, number, email));
    endInsertRows();

}

void QContactList::edit(int index, QString name, QString number, QString email){
    list[index].modify(name, number, email);
    emit dataChanged(createIndex(index,0), createIndex(index,2));
}

void QContactList::remove(int index){
    beginRemoveRows(QModelIndex(), index, index); //let's experiment!
    list.removeAt(index);
    endRemoveRows();
}

void QContactList::bookmark_change(int index){
    list[index].bookmark_change();
}

bool QContactList::bookmarked(int index){
    return list[index].bookmark();
}

Contact QContactList::operator[](int index){
    return list[index];
}


