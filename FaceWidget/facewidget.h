#ifndef FACEWIDGET_H
#define FACEWIDGET_H

#include "facewidget_global.h"
#include <QWidget>

struct DataInfo{

    QString placeName;
    QString defaultStr;
    QString helpName;

    DataInfo(QString pName,QString defStr,QString hName):placeName(pName),defaultStr(defStr),helpName(hName){}
};

class FACEWIDGETSHARED_EXPORT FaceWidget:public QWidget
{

public:
    FaceWidget(QWidget *parent = nullptr);
private:
    void LoadView();
private:
    QList<DataInfo> infos;
};

#endif // FACEWIDGET_H
