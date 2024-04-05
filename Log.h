#ifndef LOG_H
#define LOG_H
#include <QTextStream>

class Ilog
{
public:
    virtual void log(const QString &str) const = 0;
};

class ConsoleLog : public Ilog
{
public:
    void log(const QString &str) const override
    {
        QTextStream cout(stdout);
        cout << str << Qt::endl;
    }
};
#endif // LOG_H
