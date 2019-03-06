#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    LoadMenu();
    LoadFace();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadMenu()
{
    auto mb = menuBar();


    auto mn = mb->addMenu("菜单");

    //auto act = mn->addAction("");

    mn->addSeparator();
    auto act = mn->addAction("退出");
    {
        connect(act,&QAction::triggered,this,&QWidget::close);
    }

    mn = mb->addMenu("界面");
    act = mn->addAction("显示界面");
    {
        connect(act,&QAction::triggered,[&](){
            auto dock = face_dock;
            if(dock == nullptr)
            {
                dock = new QDockWidget("显示界面");
                dock ->setMinimumWidth(240);
                addDockWidget(Qt::TopDockWidgetArea,dock);
                dock->setAllowedAreas(Qt::TopDockWidgetArea);

                dock->setWidget(face_widget = new FaceWidget);


            }else
            {
                dock->show();
            }
        });
    }


}
void MainWindow::LoadFace()
{

}
