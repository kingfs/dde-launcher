#ifndef DBUSTYPE_H
#define DBUSTYPE_H
#include <QtCore>
#include <QtDBus>

class  CategoryInfo
{

public:
    QString name;
    qlonglong id;
    QStringList items;

    CategoryInfo();
    ~CategoryInfo();

    friend QDBusArgument &operator<<(QDBusArgument &argument, const CategoryInfo &obj);

    friend const QDBusArgument &operator>>(const QDBusArgument &argument, CategoryInfo &obj);

    static void registerMetaType();
};



class  AppFrequencyInfo
{

public:
    QString key;
    qulonglong count;

    AppFrequencyInfo();
    ~AppFrequencyInfo();

    friend QDBusArgument &operator<<(QDBusArgument &argument, const AppFrequencyInfo &obj);

    friend const QDBusArgument &operator>>(const QDBusArgument &argument, AppFrequencyInfo &obj);

    static void registerMetaType();
};

class  AppInstalledTimeInfo
{

public:
    QString key;
    qlonglong installedTime;

    AppInstalledTimeInfo();
    ~AppInstalledTimeInfo();

    friend QDBusArgument &operator<<(QDBusArgument &argument, const AppInstalledTimeInfo &obj);

    friend const QDBusArgument &operator>>(const QDBusArgument &argument, AppInstalledTimeInfo &obj);

    static void registerMetaType();
};


class ItemInfo
{
public:
    QString url;
    QString name;
    QString key;
    QString iconKey;
    qlonglong id;
    qlonglong installedTime;

    /*add url*/
    bool isAutoStart=false;
    QString icon;
    qulonglong count = 0;
    QString pinyinName;
    QString lowerPinyinName;

    ItemInfo();
    ~ItemInfo();

    friend QDBusArgument &operator<<(QDBusArgument &argument, const ItemInfo &obj);

    friend const QDBusArgument &operator>>(const QDBusArgument &argument, ItemInfo &obj);

    static void registerMetaType();
};


typedef QList<CategoryInfo> CategoryInfoList;
Q_DECLARE_METATYPE(CategoryInfo)
Q_DECLARE_METATYPE(CategoryInfoList)

typedef QList<AppFrequencyInfo> AppFrequencyInfoList;
Q_DECLARE_METATYPE(AppFrequencyInfo)
Q_DECLARE_METATYPE(AppFrequencyInfoList)

typedef QList<AppInstalledTimeInfo> AppInstalledTimeInfoList;
Q_DECLARE_METATYPE(AppInstalledTimeInfo)
Q_DECLARE_METATYPE(AppInstalledTimeInfoList)

typedef QList<ItemInfo> AllItemInfosList;
Q_DECLARE_METATYPE(ItemInfo)
Q_DECLARE_METATYPE(AllItemInfosList)


#endif // DBUSTYPE_H
