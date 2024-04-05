#include <QCoreApplication>
#include <QFile>
#include "Log.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ConsoleLog l;
    QString str = "D:\\qt\\File_Tracking\\test.txt";
    QFile f(str);
    if (f.exists()) l.log("+"); else l.log("-");
    return a.exec();
}
