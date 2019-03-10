#ifndef CAR_H
#define CAR_H

#import <iostream>

#include <QApplication>

using namespace std;

class Car
{
private:
    QString name;
    int nWheels;
    int power;
    string color;
    string plate;
    bool kidsB;
    bool multipleB;
    bool giantG;
    bool secondWheel;
    bool kit;
    string oil;

public:
    Car();

    //getters

    QString getName();
    int getNWheels();
    int getPower();
    string getColor();
    string getPlate();
    bool getKidsB();
    bool getMultipleB();
    bool getGiantG();
    bool getSecondWheel();
    bool getKit();
    string getOil();

    //setters

    void setName(QString n);
    void setNWheels(int n);
    void setPower(int p);
    void setColor(string c);
    void setPlate(string p);
    void setKidsB(bool a);
    void setMultipleB(bool a);
    void setGiantG(bool a);
    void setSecondWheel(bool a);
    void setKit(bool a);
    void setOil(string o);


};

#endif // CAR_H
