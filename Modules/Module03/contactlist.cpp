#include "contactlist.h"
#include "contact.h"

ContactList::ContactList(){}

ContactList::~ContactList(){}

ContactList::ContactList(const ContactList& contact){
    list = contact.list;
}

ContactList& ContactList::operator= (const ContactList& contact){
    this->list = contact.list;

    return *this;
}

void ContactList::add(Contact contact){
    list.append(contact);
}

int ContactList::remove(int idx){
    if (0 <= idx && idx < list.size()){
        list.erase(list.begin() + idx - 1);
        return 0;
    }
    else{
        return -1;
    }
}

Contact ContactList::operator[] (int idx){
    if (0 <= idx && idx < list.size()){
        return list[idx];
    }
    else{
        return Contact(true);
    }
}

int ContactList::search_idx(QString info, QString goal){
    int search_var;

    if (info == "name"){
        search_var = 0;
    }
    else if(info == "number"){
        search_var = 1;
    }
    else if(info == "email"){
        search_var = 2;
    }
    else{
        return -1;
    }

    int index = -1;

    for (int i = 0; i < list.size(); i++){
        QString search_arr[3] = {list[i].showName(), list[i].showNumber(), list[i].showEmail()};

        if (search_arr[search_var] == goal){
            index = i;
            break;
        }
    }

    return index;
}


Contact ContactList::search(QString info, QString goal){
    int search_var;

    if (info == "name"){
        search_var = 0;
    }
    else if(info == "number"){
        search_var = 1;
    }
    else if(info == "email"){
        search_var = 2;
    }
    else{
        return Contact(true);
    }

    Contact contact = Contact(true);

    for (int i = 0; i < list.size(); i++){
        QString search_arr[3] = {list[i].showName(), list[i].showNumber(), list[i].showEmail()};

        if (search_arr[search_var] == goal){
            contact = list[i];
            break;
        }
    }

    return contact;
}

int ContactList::len(){
    return list.size();
}
