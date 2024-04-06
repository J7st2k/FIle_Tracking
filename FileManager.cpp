#include "FileManager.h"

FileManager::FileManager(Ilog *logg)
{
    setLog(logg);

    connect(this, &FileManager::upd_signal, this, &FileManager::update);
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

void FileManager::check()
{
    QFileInfo q;
    for (int i=0; i < x.length(); i++) {
        q.setFile(x[i]->getUrl());
        if (q.exists() != x[i]->getExist() || q.size() != x[i]->getSize()) {
            x[i]->update(q.size(), q.exists());
            emit upd_signal(x[i]);
        }
    }
}

FileManager::~FileManager()
{
    for (int i = 0; i<x.size(); i++) {
        delete x[i];
        x[i] = nullptr;
    }
}

void FileManager::update(File* F)
{
    if (F->getExist()) l->log(QString("File ") + F->getUrl() + QString(" has been changed. Current size: ") + QString::number(F->getSize()));
    else l->log(QString("File ") + F->getUrl() + QString(" has been deleted."));
}
