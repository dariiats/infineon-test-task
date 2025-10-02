#ifndef NUMBERS_H
#define NUMBERS_H

#include <QObject>
#include <QQueue>
#include <QMutex>
#include <QListWidget>
#include <QWaitCondition>

class Numbers : public QObject {
    Q_OBJECT
public:
    Numbers(QListWidget *QListWidget_generat, QListWidget *QListWidget_queue, QListWidget *QListWidget_loose, QObject *parent = nullptr);
public slots:
    void createNum();

    void writeLooseNum();

    void setLooseRunning(bool running);

    void writeNum();

    void printNum();

    void printLoose();

    void printQueue();
private:
    int newNumber = -1;
    int looseNum = -1;

    QQueue<int> queue;

    QMutex mtx;

    QListWidget *QListWidget_generat;
    QListWidget *QListWidget_queue;
    QListWidget *QListWidget_loose;

    QWaitCondition canWrite;
    QWaitCondition canGenerate;
    QWaitCondition canLoose;

    bool numberReady = false;
    bool looseReady = false;
    bool looseRunning = false;
};

#endif // NUMBERS_H

