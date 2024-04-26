#ifndef FILE_H
#define FILE_H
#include <QFileInfo>

class File
{
private:
    QString url;
    qint64 size;
    bool exist;

public:
    File(const QString &str);

    void update();

    QString getUrl();
    qint64 getSize();
    bool getExist();
};

#endif // FILE_H
