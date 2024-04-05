#include "File.h"

File::File(const QString &str)
{
    QFile f(str);
}
