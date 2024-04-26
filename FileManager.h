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
    FileManager(Ilog* logg);
    ~FileManager();
    FileManager(FileManager const&);
    FileManager& operator= (FileManager const&);
protected:
    QVector <File*> x;
    Ilog* l;
public:
    static FileManager& Instance(Ilog* logg);
    void addFile(const QString &str);
    void setLog(Ilog *logg);
    void check();
signals:
    void upd_signal(File* F);
    void log_signal(const QString &str);
private slots:
    void update(File* F);
};

#endif // FILEMANAGER_H
