#include <iostream>

using namespace std;

class Polygon
{
protected:
    int width, height;

public:
    void setValues(int a, int b)
    {
        width = a;
        height = b;
    }

    virtual int area() const = 0;
    void printArea() const
    {
        cout << area() << endl;
    }
};

class Rectangle : public Polygon
{
public:
    int area() const 
    {
        return width * height;
    }
};

class Triangle : public Polygon
{
public:
    int area() const 
    {
        return width * height / 2;
    }
};

int main()
{
    Rectangle rect;
    Triangle trgl;
    Polygon * ppoly1 = &rect;
    Polygon * ppoly2 = &trgl;
    ppoly1->setValues(2, 19);
    ppoly2->setValues(2, 19);

    ppoly1->printArea();
    ppoly2->printArea();

    cout << ppoly1->area() << endl;
    cout << ppoly2->area() << endl;
    


    return 0;
}