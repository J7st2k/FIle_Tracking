#include "File.h"

File::File(const QString &str):url(str) {
    QFileInfo q(url);
    exist = q.exists();
    size = q.size();
}
