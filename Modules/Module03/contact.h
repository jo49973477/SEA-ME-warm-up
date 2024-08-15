#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
using namespace std;

class Contact
{
    QString name, number, email;
    bool bookmarked;
    bool failed = false;
public:

    Contact();
    Contact(QString name, QString, QString);
    Contact(bool failed);
    ~Contact();
    Contact(const Contact& contact);
    Contact& operator= (const Contact& contact);

    void modify(QString, QString, QString);
    void bookmark_change();
    bool isFailed();
    QString showName();
    QString showNumber();
    QString showEmail();
    bool bookmark();
};

#endif // CONTACT_H
