#include <QCoreApplication>
#include <QFile>
#include "FileManager.h"
#include <chrono>
#include <thread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ConsoleLog l;
    QString str = "D:\\qt\\File_Tracking\\test1.txt";
    FileManager FM(&l);
    FM.addFile(str);
    str = "D:\\qt\\File_Tracking\\test2.txt";
    FM.addFile(str);
    FM.check();
    while (true) {
        std::this_thread::sleep_for( std::chrono::milliseconds(100) );
        FM.check();
    };
    return a.exec();
}
