#ifndef QCONTACTLIST_H
#define QCONTACTLIST_H

#include <QAbstractListModel>
#include "contact.h"

enum enRole{
    nName = Qt::UserRole,
    nNumber,
    nEmail
};

class QContactList : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit QContactList(QObject *parent = nullptr);
    ~QContactList();
    QContactList(const QContactList& qlist);
    QContactList& operator= (const QContactList& other);

    virtual int rowCount(const QModelIndex & = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int nRole) const;
    void add(QString, QString, QString);
    void edit(int, QString, QString, QString);
    void remove(int index);
    void bookmark_change(int index);
    bool bookmarked(int index);
    Contact operator[](int index);


protected:
    virtual QHash<int, QByteArray> roleNames() const;

private:
    QList<Contact> list;
};

#endif // QCONTACTLIST_H
