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
};