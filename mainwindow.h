#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <vector>
#include <QMessageBox>

#include "car.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Guardar_clicked();

    void on_GenerarMatricula_clicked();

    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_potencia_sliderMoved(int position);

private:
    Ui::MainWindow *ui;

    vector<Car> vehicles;

    int counter = 0;

    int secondCounter = 0;

};

#endif // MAINWINDOW_H
