#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "car.h"
#include <time.h>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

string intToLetter(int num)
{
    string letter[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    return letter[num];

}
void MainWindow::on_GenerarMatricula_clicked()
{
    string plate;
    int num = 0;
    QString qstr;

    srand(time(NULL));
    for(int i = 0; i < 4; i++)
    {
        num = rand() % 10;
        plate += to_string(num);
    }
    for(int i = 0; i < 3; i++)
    {
        num = rand() % 10;

        plate += intToLetter(num);
    }

    qstr = QString::fromStdString(plate);

    ui->matricula->setText(qstr);
}


void MainWindow::on_Guardar_clicked()
{
    Car nuevo;
    int contadorHomer = 0;

    nuevo.setName(ui->nombreCoche->text());

    if(ui->DosRuedas->isChecked() ==  true)
    {
        nuevo.setNWheels(2);
    }
    if(ui->TresRuedas->isChecked() == true)
    {
        nuevo.setNWheels(3);
    }
    if(ui->CuatroRuedas->isChecked() == true)
    {
        nuevo.setNWheels(4);
    }

    if(ui->ColorAzul->isChecked() == true)
    {
        nuevo.setColor("Azul");
    }
    if(ui->ColorAmarillo->isChecked() == true)
    {
        nuevo.setColor("Amarillo");
    }
    if(ui->ColorVerde->isChecked() == true)
    {
        nuevo.setColor("Verde");
    }
    if(ui->ColorRojo->isChecked() == true)
    {
        nuevo.setColor("Rojo");
    }

    nuevo.setPlate(ui->matricula->text().toStdString());

    if(ui->BNinios->isChecked() == true)
    {
        nuevo.setKidsB(true);
        contadorHomer++;
    }
    if(ui->MBocinas->isChecked())
    {
        nuevo.setMultipleB(true);
        contadorHomer++;
    }
    if(ui->PVasos->isChecked() == true)
    {
        nuevo.setGiantG(true);
        contadorHomer++;
    }

    if(ui->RuedaRepuesto->isChecked() == true)
    {
        nuevo.setSecondWheel(true);
    }
    if(ui->Kit->isChecked() == true)
    {
        nuevo.setKit(true);
    }

    nuevo.setOil(ui->Combustible->currentText().toStdString());
    nuevo.setPower(ui->potencia->value());

    if(nuevo.getName() == NULL)
    {
        QMessageBox::StandardButton reply = QMessageBox::warning(this, "SIN NOMBRE", "A su vehículo le falta un nombre");
    }
    else if(contadorHomer > 0 && contadorHomer < 3)
    {
        QMessageBox::StandardButton reply = QMessageBox::warning(this, "SIN NOMBRE", "No es posible crear su vehículo. O todas las opciones marcadas o ninguna");
    }
    else if(nuevo.getNWheels() == NULL)
    {
        QMessageBox::StandardButton reply = QMessageBox::warning(this, "SIN NUMERO DE RUEDAS", "A su vehículo le falta un numero de ruedas");
    }
    else if(QString::fromStdString(nuevo.getColor()) == NULL)
    {
        QMessageBox::StandardButton reply = QMessageBox::warning(this, "SIN COLOR", "Su vehículo no tiene color");
    }
    else if(QString::fromStdString(nuevo.getPlate()) == NULL)
    {
        QMessageBox::StandardButton reply = QMessageBox::warning(this, "SIN MATRICULA", "A su vehículo le falta la matricula");
    }
    else if(QString::fromStdString(nuevo.getOil()) == NULL)
    {
        QMessageBox::StandardButton reply = QMessageBox::warning(this, "SIN COMBUSTIBLE", "Debe especificar el combustible de su vehículo");
    }
    else
    {
        vehicles.push_back(nuevo);
        counter++;
        if(contadorHomer == 3 && nuevo.getNWheels() == 4)
        {
            QMessageBox::StandardButton reply = QMessageBox::question(this, "My title", "Coche de homer guardado con exito!");
        }
        else if(nuevo.getNWheels() == 2)
        {
            QMessageBox::StandardButton reply = QMessageBox::question(this, "My title", "Moto guardada con exito!");
        }
        else if(nuevo.getNWheels() == 3)
        {
            QMessageBox::StandardButton reply = QMessageBox::question(this, "My title", "Triciclo guardado con exito!");
        }
        else
        {
            QMessageBox::StandardButton reply = QMessageBox::question(this, "My title", "Coche guardado con exito!");
        }

        ui->nombreCoche->setText(NULL);

        ui->DosRuedas->setAutoExclusive(false);
        ui->DosRuedas->setChecked(false);
        ui->DosRuedas->setAutoExclusive(true);

        ui->TresRuedas->setAutoExclusive(false);
        ui->TresRuedas->setChecked(false);
        ui->TresRuedas->setAutoExclusive(true);

        ui->CuatroRuedas->setAutoExclusive(false);
        ui->CuatroRuedas->setChecked(false);
        ui->CuatroRuedas->setAutoExclusive(true);

        ui->ColorRojo->setAutoExclusive(false);
        ui->ColorRojo->setChecked(false);
        ui->ColorRojo->setAutoExclusive(true);

        ui->ColorAzul->setAutoExclusive(false);
        ui->ColorAzul->setChecked(false);
        ui->ColorAzul->setAutoExclusive(true);

        ui->ColorAmarillo->setAutoExclusive(false);
        ui->ColorAmarillo->setChecked(false);
        ui->ColorAmarillo->setAutoExclusive(true);

        ui->ColorVerde->setAutoExclusive(false);
        ui->ColorVerde->setChecked(false);
        ui->ColorVerde->setAutoExclusive(true);

        ui->matricula->setText(NULL);

        ui->BNinios->setChecked(false);
        ui->MBocinas->setChecked(false);
        ui->PVasos->setChecked(false);

        ui->RuedaRepuesto->setAutoExclusive(false);
        ui->RuedaRepuesto->setChecked(false);
        ui->RuedaRepuesto->setAutoExclusive(true);

        ui->Kit->setAutoExclusive(false);
        ui->Kit->setChecked(false);
        ui->Kit->setAutoExclusive(true);

        ui->potencia->setValue(75);
        ui->Combustible->setCurrentText(NULL);
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{

}

void MainWindow::on_pushButton_clicked()
{
    QString nombreVehiculo;
    int numRuedas;
    int potencia;
    QString color;
    QString matricula;
    QString combustible;

    if(counter != 0)
    {
        if(secondCounter == counter)
        {
            secondCounter = 0;
        }
        ui->ContadorCoches->setText(QString::number(secondCounter + 1));
        nombreVehiculo = vehicles[secondCounter].getName();
        numRuedas = vehicles[secondCounter].getNWheels();
        potencia = vehicles[secondCounter].getPower();
        color = QString::fromStdString(vehicles[secondCounter].getColor());
        matricula = QString::fromStdString(vehicles[secondCounter].getPlate());
        combustible = QString::fromStdString(vehicles[secondCounter].getOil());

        ui->Label_nombre->setText(nombreVehiculo);
        ui->Label_ruedas->setText(QString::number(numRuedas));
        ui->Label_Potencia->setText(QString::number(potencia));
        ui->Label_color->setText(color);
        ui->Label_matricula->setText(matricula);
        ui->Label_combustible->setText(combustible);

        secondCounter++;
    }
}

void MainWindow::on_potencia_sliderMoved(int position)
{
    ui->contador_potencia->setNum(position);
}
