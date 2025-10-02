#include <QObject>
#include <QDebug>
#include <QThread>
#include <QQueue>
#include <QMutex>
#include <QRandomGenerator>
#include <QListWidget>
#include "numbers.h"

Numbers::Numbers(QListWidget *QListWidget_generat, QListWidget *QListWidget_queue, QListWidget *QListWidget_loose, QObject *parent) :
    QObject(parent),
    QListWidget_generat(QListWidget_generat),
    QListWidget_queue(QListWidget_queue),
    QListWidget_loose(QListWidget_loose)
{}

void Numbers::createNum()
{
    QMutexLocker locker(&mtx);

    while (numberReady) {
        canGenerate.wait(&mtx);
    }

    newNumber++;
    numberReady = true;

    canWrite.wakeOne();
}

void Numbers::writeLooseNum()
{
    QMutexLocker locker(&mtx);

    if(!queue.isEmpty() && queue.size() == 20)
    {
        looseNum = queue.front();
        looseReady = true;

        canWrite.wakeOne();
    }
}

void Numbers::setLooseRunning(bool running) {
    QMutexLocker locker(&mtx);
    looseRunning = running;
}

void Numbers::writeNum()
{
    QMutexLocker locker(&mtx);

    while (!numberReady) canWrite.wait(&mtx);

    if(queue.size() == 20)
    {
        while(!looseReady && looseRunning) canWrite.wait(&mtx);

        queue.dequeue();

        looseReady = false;
    }

    queue.enqueue(newNumber);

    numberReady = false;

    canGenerate.wakeOne();
}

void Numbers::printNum()
{
    QListWidget_generat->clear();

    if(newNumber != -1) QListWidget_generat->addItem(QString::number(newNumber));
}

void Numbers::printLoose()
{
    QListWidget_loose->clear();

    if(looseNum != -1) QListWidget_loose->addItem(QString::number(looseNum));
}

void Numbers::printQueue()
{
    QListWidget_queue->clear();

    for (int i = 0; i < queue.size(); ++i) {
        QListWidget_queue->addItem(QString::number(queue.at(i)));
    }
}
