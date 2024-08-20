#include "bookmarkfilterproxymodel.h"
#include "qcontactlist.h"

BookmarkFilterProxyModel::BookmarkFilterProxyModel(QSortFilterProxyModel *parent)
    : QSortFilterProxyModel{parent}
{}

BookmarkFilterProxyModel::~BookmarkFilterProxyModel(){}

bool BookmarkFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const{
    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
    bool bookmarked = sourceModel()->data(index, nBookmark).toBool();
    return bookmarked;
}

int BookmarkFilterProxyModel::original_index(int index){
    QModelIndex proxyIndex = this->index(index, 0);
    QModelIndex source_modelidx = mapToSource(proxyIndex);
    return source_modelidx.row();
}
