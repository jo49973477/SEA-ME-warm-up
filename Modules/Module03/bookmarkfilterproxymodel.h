#ifndef BOOKMARKFILTERPROXYMODEL_H
#define BOOKMARKFILTERPROXYMODEL_H

#include "qsortfilterproxymodel.h"
#include <QObject>

class BookmarkFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit BookmarkFilterProxyModel(QSortFilterProxyModel *parent = nullptr);
    ~BookmarkFilterProxyModel();

    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
    int original_index(int index);
signals:
};

#endif // BOOKMARKFILTERPROXYMODEL_H
