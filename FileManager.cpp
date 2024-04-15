#include "FileManager.h"

FileManager::FileManager(Ilog *logg)
{
    setLog(logg);

    connect(this, &FileManager::upd_signal, this, &FileManager::update);
}

void FileManager::addFile(const QString &str)
{
    QRegExp checkPath(QString("(.*):(\\\\.*)*(\..*)"));
    if(checkPath.exactMatch(str)) {
        File* F = new File(str);
        x.push_back(F);
        emit log_signal(QString("File ") + str + QString(" added. Size: ") + QString::number(F->getSize()));
    } else emit log_signal(QString("File path ") + str + QString(" is invalid."));
}

void FileManager::setLog(Ilog *logg)
{
    if (logg) {
        l = logg;
        connect(this, &FileManager::log_signal, l, &Ilog::log);
    }
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
        emit log_signal(QString("File ") + F->getUrl() + QString(" has been created. Current size: ") + QString::number(F->getSize()));
    } else if (ex) {
        F->update(s, ex);
        emit log_signal(QString("File ") + F->getUrl() + QString(" has been changed. Current size: ") + QString::number(F->getSize()));
    } else {
        F->update(s, ex);
        emit log_signal(QString("File ") + F->getUrl() + QString(" has been deleted."));
    }
}
