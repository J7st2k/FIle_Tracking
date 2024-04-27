#include "FileManager.h"
#include <iostream>

FileManager::FileManager(Ilog *logg)
{
    setLog(logg);

    connect(this, &FileManager::upd_signal, this, &FileManager::update);
}

void FileManager::addFile(const QString &str)
{
    File* F = new File(str);
    x.push_back(F);
    emit log_signal(QString("File ") + str + QString(" added. Size: ") + QString::number(F->getSize()));
}

void FileManager::removeFile(const QString &str)
{
    for (int i = 0; i<x.size(); i++) {
        emit log_signal(x[i]->getUrl());
        emit log_signal(str);
        if(x[i]->getUrl() == str) {
            x.remove(i);
            x.squeeze();
            emit log_signal(QString("File ") + str + QString(" has been removed from tracking."));
            i--;
        }
    }
}

void FileManager::setLog(Ilog *logg)
{
    if (logg) {
        l = logg;
        connect(this, &FileManager::log_signal, l, &Ilog::log);
    } else std::cout << "Logger is invalid, messaging will be stopped." << std::endl;
}

void FileManager::check()
{
    QFileInfo q;
    for (int i=0; i < x.length(); i++) {
        q.setFile(x[i]->getUrl());
        if (q.exists() != x[i]->getExist() || q.size() != x[i]->getSize()) {
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

FileManager &FileManager::Instance(Ilog* logg)
{
    static FileManager FM(logg);
    return FM;
}

void FileManager::update(File* F)
{
    QFileInfo q;
    q.setFile(F->getUrl());
    if (!F->getExist()) {
        F->update();
        emit log_signal(QString("File ") + F->getUrl() + QString(" has been created. Current size: ") + QString::number(F->getSize()));
    } else if (q.exists()) {
        F->update();
        emit log_signal(QString("File ") + F->getUrl() + QString(" has been changed. Current size: ") + QString::number(F->getSize()));
    } else {
        F->update();
        emit log_signal(QString("File ") + F->getUrl() + QString(" has been deleted."));
    }
}
