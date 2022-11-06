#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton*** labels;
    QPushButton*** labels2;
    Ui::MainWindow *ui;
    int positionX = 0;
    int positionY = 0;

private slots:
    void celdaPresionada(QPushButton *a);
};
#endif // MAINWINDOW_H
