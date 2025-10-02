#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtConcurrent>
#include "numbers.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void startGenerator();
    void stopGenerator();
    void startLoose();
    void stopLoose();
    void updateWidgets();

private:
    Ui::MainWindow *ui;
    Numbers *num;
    QFuture<void> future_generat;
    QFuture<void> future_queue;
    QFuture<void> future_loose;

    bool generatorRunning = false;
    bool looseRunning = false;

    QTimer* updateTimer;
};

#endif // MAINWINDOW_H
