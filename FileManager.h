#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "File.h"
#include "Log.h"
#include <QVector>
#include <QObject>
#include <QRegExp>

class FileManager:public QObject
{
    Q_OBJECT
private:
    QVector <File*> x;
    Ilog* l;

public:
    FileManager(Ilog* logg);
    void addFile(const QString &str);
    void setLog(Ilog *logg);

    void check();
    ~FileManager();
signals:
    void upd_signal(File* F);
    void log_signal(const QString &str);
public slots:
    void update(File* F);
};

#endif // FILEMANAGER_H
