#ifndef LISTCONTROL_H
#define LISTCONTROL_H

#include <QObject>
#include "QContactList.h"
#include "bookmarkfilterproxymodel.h"

class ListControl : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int len READ len NOTIFY listChanged)
    Q_PROPERTY(QString nowName READ nowName NOTIFY idxChanged)
    Q_PROPERTY(QString nowNumber READ nowNumber NOTIFY idxChanged)
    Q_PROPERTY(QString nowEmail READ nowEmail NOTIFY idxChanged)
    Q_PROPERTY(bool nowBookmark READ nowBookmark NOTIFY bookmarkChanged)
    Q_PROPERTY(bool showBookmarkedOnly READ showBookmarkedOnly NOTIFY listShowingChanged)

protected:
    int index = 0;
    QContactList list;
    BookmarkFilterProxyModel * filtered = new BookmarkFilterProxyModel();
    bool only_bookmarked = false;

public:
    explicit ListControl(QObject *parent = nullptr);
    ~ListControl();
    ListControl(const ListControl& control);
    ListControl& operator= (const ListControl& control);

    Q_INVOKABLE QContactList * getModel() {return &list;}
    Q_INVOKABLE BookmarkFilterProxyModel * getbookmarkedModel() {return filtered;}
    Q_INVOKABLE void selectRow(int idx);
    Q_INVOKABLE void add(QString name, QString number, QString email);
    Q_INVOKABLE void edit(QString name, QString number, QString email);
    Q_INVOKABLE void remove();
    Q_INVOKABLE int search(QString item, QString keyword);
    Q_INVOKABLE void bookmark_change();
    Q_INVOKABLE void list_showing_change();

    QString nowName();
    QString nowNumber();
    QString nowEmail();
    int len(){ return (only_bookmarked) ? filtered->rowCount() : list.rowCount();}
    bool nowBookmark();
    bool showBookmarkedOnly();

    void debug();

signals:
    void idxChanged();
    void listChanged();
    void bookmarkChanged();
    void listShowingChanged();

};

#endif // LISTCONTROL_H
