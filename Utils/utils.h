#ifndef UTILS_H
#define UTILS_H

#include <QApplication>

namespace MME{

class Utils
{
public:
    Utils();
    static void setupStylesheetForApp(const QString& styleSheet);
};

}
#endif // UTILS_H
