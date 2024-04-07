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
    l->log(QString("File ") + str + QString(" added. Size: ") + QString::number(F->getSize()));
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
            emit upd_signal(x[i], q.exists(), q.size());
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

void FileManager::update(File* F, const bool &ex, const qint64 &s)
{
    if (!F->getExist()) {
        F->update(s, ex);
        l->log(QString("File ") + F->getUrl() + QString(" has been created. Current size: ") + QString::number(F->getSize()));
    } else if (ex) {
        F->update(s, ex);
        l->log(QString("File ") + F->getUrl() + QString(" has been changed. Current size: ") + QString::number(F->getSize()));
    } else {
        F->update(s, ex);
        l->log(QString("File ") + F->getUrl() + QString(" has been deleted."));
    }
}
