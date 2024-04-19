#ifndef LOG_H
#define LOG_H
#include <QTextStream>
#include <QObject>

class Ilog : public QObject
{
public slots:
    virtual void log(const QString &str) const = 0;
};

class ConsoleLog : public Ilog
{
public slots:
    void log(const QString &str) const override
    {
        QTextStream cout(stdout);
        cout << str << Qt::endl;
    }
};
#endif // LOG_H
