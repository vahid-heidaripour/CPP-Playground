#ifndef __CAR_H__
#define __CAR_H__

#include <iostream>
using namespace std;

class Tire
{
protected:
    string _name;
    int _pressure;

public:
    Tire(string name, int pressure) : _name(name), _pressure(pressure) {}
    string getName() const { return _name; }
    int getPressure() const { return _pressure; }
};

class SimpleTire : public Tire
{
public:
    SimpleTire() : Tire("SimpleTire", 75) {}
};

class LuxuryTire : public Tire
{
public:
    LuxuryTire() : Tire("LuxuryTire", 100) {}
};

class Body
{
protected:
    string _name;
    int _strength;

public:
    Body(string name, int strength) : _name(name), _strength(strength) {}
    string getName() const { return _name; }
    int getStrength() const { return _strength; }
};

class SimpleBody : public Body
{
public:
    SimpleBody() : Body("SimpleBody", 75) {}
};

class LuxuryBody : public Body
{
public:
    LuxuryBody() : Body("LuxuryBody", 100) {}
};

class Car
{
protected:
    string _name;
    Tire *_tire;
    Body *_body;

public:
    Car(string name) : _name(name) {}
    void setTire(Tire *tire) { _tire = tire; }
    void setBody(Body *body) { _body = body; }

    void printDetails()
    {
        cout << endl << "Car: " << _name << endl;
        cout << "Tire: " << _tire->getName() << " ,Pressure: " << _tire->getPressure() << endl;
        cout << "Body: " << _body->getName() << " ,Strength: " << _body->getStrength() << endl;
    }
};

#endif // __CAR_H__