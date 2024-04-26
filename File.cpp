#include "File.h"

File::File(const QString &str):url(str)
{
    QFileInfo q(url);
    exist = q.exists();
    size = q.size();
}

void File::update()
{
    QFileInfo q(url);
    exist = q.exists();
    size = q.size();
}

QString File::getUrl()
{
    return url;
}

qint64 File::getSize()
{
    return size;
}

bool File::getExist()
{
    return exist;
}
