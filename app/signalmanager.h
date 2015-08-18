#ifndef SIGNALMANAGER_H
#define SIGNALMANAGER_H

#include <QObject>
#include "dbusinterface/dbustype.h"


class SignalManager : public QObject
{
    Q_OBJECT
public:
    SignalManager(QObject *parent = 0){
        Q_UNUSED(parent);
    };
    ~SignalManager(){

    };

signals:
    void categoryModeChanged(int mode);
    void sortModeChanged(int mode);
    void itemInfosChanged(const QMap<QString, ItemInfo>& itemInfos);
    void categoryInfosChanged(const CategoryInfoList& categoryInfoList);

    void hideNavigationButtonByKeys(const QStringList& buttonKeys);

    void viewRowChanged(int row);
    void navigationButtonClicked(QString key);
    void checkNavigationButtonByKey(QString key);

    /*context menu*/
    void contextMenuShowed(QString url, QPoint pos);

    /*mouse release on whole window*/
    void mouseReleased();

    /*unistall delete item in table*/
    void itemDeleted(QString appKey);

public slots:
};

#endif // SIGNALMANAGER_H