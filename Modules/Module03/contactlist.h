#ifndef CONTACTLIST_H
#define CONTACTLIST_H


#include <QVector>
#include "contact.h"

class ContactList
{
    QVector<Contact> list;
public:
    ContactList();
    ~ContactList();
    ContactList(const ContactList& contact);
    ContactList& operator= (const ContactList& contact);

    void add(Contact contact);
    int remove(int idx);

    Contact operator[] (int index);
    int search_idx(QString info, QString name);
    Contact search(QString info, QString name);
    int len();
};

#endif // CONTACTLIST_H
