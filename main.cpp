#include "mainwindow.h"
#include <QApplication>

// test
#include <QList>
#include <QString>

#include "FFmpeg/Test/t_1_hellowffmpeg.h"
//

#include "Utils/utils.h"
#include "mme.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // setup stylesheet
    MME::Utils::setupStylesheetForApp(QString(MME::MME::GStyleSheetFilePath()));
    // test
    //T_1_HellowFFmpeg ffmpeg;
    //ffmpeg.show_all_support_info();
    //
    MainWindow w;
    w.show();

    return a.exec();
}
