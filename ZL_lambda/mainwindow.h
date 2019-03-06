#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QWidget>
#include "FaceWidget/facewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void LoadMenu();
    void LoadFace();
private:
    Ui::MainWindow *ui;
    QDockWidget *face_dock = nullptr;
    FaceWidget *face_widget;

};

#endif // MAINWINDOW_H
