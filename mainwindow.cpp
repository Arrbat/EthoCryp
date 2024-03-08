#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenRect = screen->geometry();
    this->resize(screenRect.width(), screenRect.height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

