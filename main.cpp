#include <QCoreApplication>
#include <QFile>
#include "FileManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ConsoleLog l;
    QString str = "D:\\qt\\File_Tracking\\test.txt";
    FileManager FM(&l);
    FM.addFile(str);
    return a.exec();
}
