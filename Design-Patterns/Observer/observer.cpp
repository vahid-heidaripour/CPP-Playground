#include <iostream>
#include <vector>

using namespace std;

class Car
{
    int position;
    std::vector<class Observer*> observerList;

public:
    int getPosition() const { return position; }
    void setPosition(int newPosition)
    {
        position = newPosition;
        notify();
    }
    void attach(Observer *obs)
    {
        observerList.push_back(obs);
    }
    void detach(Observer *obs)
    {
        observerList.erase(std::remove(observerList.begin(), observerList.end(), obs), observerList.end());
    }
    void notify();
};

class Observer
{
    Car *_car;

public:
    Observer(Car *car)
    {
        _car = car;
        _car->attach(this);
    }

    virtual void update() = 0;

protected:
    Car* getCar()
    {
        return _car;
    }
};

void Car::notify()
{
    for (int i = 0; i < observerList.size(); ++i)
    {
        observerList[i]->update();
    }
}

class LeftObserver : public Observer
{
public:
    LeftObserver(Car *car) : Observer(car){}
    void update()
    {
        int pos = getCar()->getPosition();
        if (pos < 0)
            cout << "left side" << endl;
    }
};

class RightObserver : public Observer
{
public:
    RightObserver(Car *car) : Observer(car){}
    void update()
    {
        int pos = getCar()->getPosition();
        if (pos > 0)
            cout << "right side" << endl;
    }
};

class MiddleObserver : public Observer
{
public:
    MiddleObserver(Car *car) : Observer(car){}
    void update()
    {
        int pos = getCar()->getPosition();
        if (pos == 0)
            cout << "running in middle" << endl;
    }
};

int main()
{
    Car *car = new Car();

    LeftObserver leftObserver(car);
    RightObserver rightObserver(car);
    MiddleObserver middleObserver(car);

    cout << "hit left right button to drive a car in your city!!!" << endl;
    cout << "l for left, r for right, c for center, and b for exit" << endl;

    char pressButton;
    bool breakLoop = false;

    while (!breakLoop)
    {
        cin >> pressButton;

        switch (pressButton)
        {
            case 108: // pressed l for left
            {
                car->setPosition(-1);
                break;
            }
            case 99: // pressed c for center
            {
                car->setPosition(0);
                break;
            }
            case 114: // pressed r for right
            {
                car->setPosition(1);
                break;
            }
            case 98: // pressed b for break
            {
                breakLoop = true;
                break;
            }
            default:
            {
                cout << "please drive carefully!!!" << endl;
                break;
            }
        }
    }

    cout << "Bye..." << endl;

    return 0;
}