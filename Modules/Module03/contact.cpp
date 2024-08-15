#include "contact.h"
using namespace std;


Contact::Contact(): name("John Doe"), number("+0112345678"), email("UNKNOWN@gmail.com"), bookmarked(false){
}


Contact::Contact(QString name, QString number, QString email):
    name(name), number(number), email(email), bookmarked(false){}


Contact::~Contact(){}

Contact::Contact(const Contact& contact):
    name(contact.name), number(contact.number), email(contact.email), bookmarked(contact.bookmarked){}


Contact::Contact(bool failed):
    name("to judge failure"), number(""), email(""), bookmarked(false), failed(failed){}

Contact& Contact::operator= (const Contact& contact){
    this->name = contact.name;
    this->number = contact.number;
    this->email = contact.email;
    this->bookmarked = contact.bookmarked;

    return *this;
}


void Contact::modify(QString name, QString number, QString email){
    this->name = name;
    this->number = number;
    this->email = email;
}

void Contact::bookmark_change(){
    bookmarked = !bookmarked;
}

bool Contact::isFailed(){
    return failed;
}

QString Contact::showName(){
    return name;
}

QString Contact::showNumber(){
    return number;
}

QString Contact::showEmail(){
    return email;
}

bool Contact::bookmark(){
    return bookmarked;
}
