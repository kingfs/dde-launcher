#ifndef SECTIONTABLEWIDGET_H
#define SECTIONTABLEWIDGET_H

#include "basetablewidget.h"
#include "dbusinterface/dbustype.h"
class QWheelEvent;
class CategoryItem;

static int categoryItemHeight = 80;

class CategoryTableWidget : public BaseTableWidget
{
    Q_OBJECT
public:
    explicit CategoryTableWidget(QWidget *parent = 0);
    ~CategoryTableWidget();
    void initConnect();

signals:

public slots:
    void setGridParameter(int column, int girdWidth, int itemWidth);
    void setItemInfosMap(const QMap<QString, ItemInfo>& itemInfos);
    void setCategoryInfoList(const CategoryInfoList& categoryInfoList);

    void addCategoryItem(int row,  QString key);
    void addItems(int row, QString categoryKey, QStringList appKeys);
    void addItems(const CategoryInfoList& categoryInfoList);

    void handleScrollBarValueChanged(int value);
    void scrollToCategory(QString key);

protected:
    void wheelEvent(QWheelEvent* event);
private:
    int m_column;
    int m_gridWidth;
    int m_itemWidth;
    QStringList m_hideKeys;
    QMap<QString, ItemInfo> m_itemInfosMap;
    CategoryInfoList m_categoryInfoList;
    CategoryInfoList m_sortedCategoryInfoList;
    QMap<QString, CategoryItem*> m_categoryItems;
};

#endif // SECTIONTABLEWIDGET_H