#ifndef FILE_H
#define FILE_H
#include <QFileInfo>
#include <QVector>
#include <QObject>

class File
{
public:
    QString url;
    qint64 size;
    bool exist;
    File(const QString &str):url(str) {
        QFileInfo q(url);
        exist = q.exists();
        size = q.size();
    }

};


#endif // FILE_H
