#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QListWidget>
#include <QtConcurrent>
#include "numbers.h"
#include <QListWidget>
#include "thread_helping.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    num = new Numbers(ui->listWidget_generat, ui->listWidget_queue, ui->listWidget_looseNum, this);

    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateWidgets);
    updateTimer->start(333);

    connect(ui->pushButton_startGenerat, &QPushButton::clicked, this, &MainWindow::startGenerator);
    connect(ui->pushButton_stopGenerat, &QPushButton::clicked, this, &MainWindow::stopGenerator);
    connect(ui->pushButton_startLoose, &QPushButton::clicked, this, &MainWindow::startLoose);
    connect(ui->pushButton_stopLoose, &QPushButton::clicked, this, &MainWindow::stopLoose);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGenerator()
{
    if(!Thread_helping::IsRunning(generatorRunning, ui->label_stateGenerat)){

    generatorRunning = true;

    future_generat = QtConcurrent::run([this](){
        while(generatorRunning) {
            num->createNum();
            QThread::msleep(333);}});
    future_queue = QtConcurrent::run([this](){
        while(generatorRunning) {
            num->writeNum();
            QThread::msleep(333);}});
    }
}


void MainWindow::stopGenerator()
{
    if (!Thread_helping::NotRunning(generatorRunning, ui->label_stateGenerat))
        generatorRunning = false;
}

void MainWindow::startLoose()
{
    if(!Thread_helping::IsRunning(looseRunning, ui->label_stateLoose))
    {
    looseRunning = true;

    num->setLooseRunning(looseRunning);

    future_loose = QtConcurrent::run([this](){
        while(looseRunning) num->writeLooseNum();});
    }
}

void MainWindow::stopLoose()
{
    if(!Thread_helping::NotRunning(looseRunning, ui->label_stateLoose)) looseRunning = false;

    num->setLooseRunning(looseRunning);
}

void MainWindow::updateWidgets()
{
    num->printNum();
    num->printQueue();
    num->printLoose();
}
