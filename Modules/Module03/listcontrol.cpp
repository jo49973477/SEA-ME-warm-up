#include <QFile>
#include "listcontrol.h"

ListControl::ListControl(QObject *parent){
}

ListControl::~ListControl(){
}

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
    emit bookmarkChanged();
}

void ListControl::add(QString name, QString number, QString email){
    list.add(name, number, email);
    emit listChanged();
    debug();
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

int ListControl::search(QString item, QString keyword){
    int search_idx = 0;

    if (item == "name"){
        search_idx = 0;
    }
    else if(item == "number"){
        search_idx = 1;
    }
    else if(item == "email"){
        search_idx = 2;
    }
    else{
        selectRow(-1);
        return -1;
    }

    int idx = -1;

    for (int i = 0; i < list.rowCount(); i++){
        QString var[3] = {list[i].showName(), list[i].showNumber(), list[i].showNumber()};
        if(var[search_idx].contains(keyword , Qt::CaseInsensitive)){
            idx = i;
            break;
        }
    }

    selectRow(idx);
    return idx;
}

void ListControl::bookmark_change(){
    list.bookmark_change(index);
    emit bookmarkChanged();
}

bool ListControl::nowBookmark(){
    if (index < 0){
        return false;
    }

    return list[index].bookmark();
}
