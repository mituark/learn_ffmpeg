#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    this->setWindowTitle(MME::MME::AppName());

    mPlayer = new MME::Player();
    // update timestamp
    QObject::connect(ui->pushButtonOpen,SIGNAL(released()),this,SLOT(slotOnOpenFile()));
    QObject::connect(ui->pushButtonStop,SIGNAL(released()),this,SLOT(slotOnStop()));
    QObject::connect(ui->pushButtonPlayPause,SIGNAL(released()),this,SLOT(slotOnPlayPause()));
}

void MainWindow::slotOnOpenFile()
{
    const QString filter = QObject::tr("Video files(*.mp3 *.mp4 *.avi *.flv)");
    QString file = QFileDialog::getOpenFileName(this, QObject::tr("Open File"), QObject::tr("/"), filter);
    if(!file.isEmpty())
    {
        qDebug()<<"open file:"<<file;
    }
}

void MainWindow::slotOnStop()
{

}

void MainWindow::slotOnPlayPause()
{

}
