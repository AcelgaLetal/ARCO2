#include "car.h"

Car::Car()
{
    kidsB = false;
    multipleB = false;
    giantG = false;
    secondWheel = false;
    kit = false;
}

QString Car::getName()
{
    return name;
}

int Car::getNWheels()
{
    return nWheels;
}

int Car::getPower()
{
    return power;
}

string Car::getColor()
{
    return color;
}

string Car::getPlate()
{
    return plate;
}

bool Car::getKidsB()
{
    return kidsB;
}

bool Car::getMultipleB()
{
    return multipleB;
}

bool Car::getGiantG()
{
    return giantG;
}

bool Car::getSecondWheel()
{
    return secondWheel;
}

bool Car::getKit()
{
    return kit;
}

string Car::getOil()
{
    return oil;
}


void Car::setName(QString n)
{
    name = n;
}

void Car::setNWheels(int n)
{
    nWheels = n;
}

void Car::setPower(int p)
{
    power = p;
}

void Car::setColor(string c)
{
    color = c;
}

void Car::setPlate(string p)
{
    plate = p;
}

void Car::setKidsB(bool a)
{
    kidsB = a;
}

void Car::setMultipleB(bool a)
{
    multipleB = a;
}

void Car::setGiantG(bool a)
{
    giantG = a;
}

void Car::setSecondWheel(bool a)
{
    secondWheel = a;
}

void Car::setKit(bool a)
{
    kit = a;
}

void Car::setOil(string o)
{
    oil = o;
}

















































