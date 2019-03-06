#include "facewidget.h"
#include <QVBoxLayout>
#include <QSplitter>
#include <QTableWidget>
#include <QHeaderView>
#include <QStringList>

FaceWidget::FaceWidget(QWidget *parent):QWidget (parent)
{
    LoadView();
}

void FaceWidget::LoadView()
{
    auto *mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    auto vLayout = new QVBoxLayout;
    {
        auto sp = new QSplitter(Qt::Horizontal);

        infos
                <<DataInfo("客厅","0","客厅PM2.5浓度")
                <<DataInfo("主卧","0","客厅PM2.5浓度")
                <<DataInfo("次卧","0","客厅PM2.5浓度")
                <<DataInfo("厕所","0","客厅PM2.5浓度")
                <<DataInfo("餐厅","0","客厅PM2.5浓度")
                <<DataInfo("健身房","0","客厅PM2.5浓度")
                <<DataInfo("书房","0","客厅PM2.5浓度");

        auto tw = new QTableWidget;
        tw->setColumnCount(2);
        tw->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        tw->horizontalHeader()->setSectionResizeMode(tw->columnCount() - 1,QHeaderView::Stretch);
        tw->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        tw->setHorizontalHeaderLabels(QStringList()<<"位置"<<"浓度");
        tw->setMinimumWidth(110);

        int ri = 0;
        int indexName = 0;
        int indexValue = 1;
        for(auto info:infos)
        {
            ri = tw->rowCount();
            tw->insertRow(ri);

            auto twi = new QTableWidgetItem(info.placeName);
            twi->setFlags(twi->flags()&~Qt::ItemIsEditable);
            twi->setToolTip(info.helpName);
            tw->setItem(ri,indexName,twi);

            twi = new QTableWidgetItem(info.defaultStr);
            twi->setFlags(twi->flags()&~Qt::ItemIsEditable);
            twi->setToolTip(info.helpName);
            tw->setItem(ri,indexValue,twi);
        }
        sp->addWidget(tw);

        vLayout->addWidget(sp);
    }
    mainLayout->addLayout(vLayout);
}
