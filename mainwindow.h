#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mme.h"

#include <QSharedPointer>
#include <QMainWindow>


#include "player.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void init();
    void initLoadSettings();
private slots:
    void slotOnOpenFile();
    void slotOnStop();
    void slotOnPlayPause();
private:
    Ui::MainWindow *ui;

    MME::Player *mPlayer;
};

#endif // MAINWINDOW_H
