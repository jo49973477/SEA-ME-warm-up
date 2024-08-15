#include "listcontrol.h"

ListControl::ListControl(QObject *parent)
    : QObject{parent}
{}

ListControl::~ListControl(){}

ListControl::ListControl(const ListControl& control): QObject(){

    index = control.index;
    list = control.list;
}

ListControl& ListControl::operator= (const ListControl& control){
    this->index = control.index;
    this->list = control.list;

    return *this;
}

void ListControl::selectRow(int idx){
    index = idx;
    emit idxChanged();
}

void ListControl::add(QString name, QString number, QString email){
    list.add(name, number, email);
    emit listChanged();
}

void ListControl::edit(int idx, QString name, QString number, QString email){
    list.edit(idx, name, number, email);
    emit listChanged();
}

void ListControl::remove(int idx){
    list.remove(idx);
    emit listChanged();
}

QString ListControl::nowName(){
    if (index < 0){
        return "";
    }
    return list[index].showName();
}

QString ListControl::nowNumber(){
    if (index < 0){
        return "";
    }
    return list[index].showNumber();
}

QString ListControl::nowEmail(){
    if (index < 0){
        return "";
    }
    return list[index].showEmail();
}

void ListControl::debug(){
    for (int i = 0; i < len(); i++){
        qDebug() << i << ": " << list[i].showName() << list[i].showNumber() << list[i].showEmail() << '\n';
    }
    qDebug() << "index" << index << '\n';
}
