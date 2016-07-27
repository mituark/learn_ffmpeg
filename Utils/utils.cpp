#include "utils.h"

#include <QFile>

namespace MME
{

Utils::Utils()
{
}

void Utils::setupStylesheetForApp(const QString &styleSheet)
{
    if(!styleSheet.isEmpty())
    {
        QFile file(styleSheet);
        if(file.open(QFile::ReadOnly))
        {
            QString content = QLatin1String(file.readAll());
            qApp->setStyleSheet(content);
        }
        file.close();
    }
}

}
