#ifndef FILE_H
#define FILE_H
#include <QFileInfo>

class File
{
public:
    QString url;
    qint64 size;
    bool exist;
    File(const QString &str);
};

#endif // FILE_H
