#include "FileManager.h"

FileManager::FileManager(Ilog *logg)
{
    setLog(logg);
}

void FileManager::addFile(const QString &str)
{
    File* F = new File(str);
    x.push_back(F);
    l->log(QString("File ") + str + QString(" added."));
}

void FileManager::setLog(Ilog *logg)
{
    if (logg) l = logg;
}

FileManager::~FileManager()
{
    for (int i = 0; i<x.size(); i++) {
        delete x[i];
        x[i] = nullptr;
    }
}
