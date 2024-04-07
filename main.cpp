#include <QCoreApplication>
#include <QFile>
#include "FileManager.h"
#include <chrono>
#include <thread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cin(stdin);

    ConsoleLog l;
    int i;
    QString ss;
    FileManager FM(&l);

    l.log("Enter the amount of files to track:");
    cin >> i;
    while (i <= 0) {
        l.log("Cant work with i <= 0. Enter new i (amount of files):");
        cin >> i;
    }

    l.log("Enter paths of your files:");
    for (int j = 0; j < i; j++) {
        cin >> ss;
        FM.addFile(ss);
    }

    // D:\\qt\\File_Tracking\\test1.txt
    while (true) {
        std::this_thread::sleep_for( std::chrono::milliseconds(100) );
        FM.check();
    };
    return a.exec();
}
