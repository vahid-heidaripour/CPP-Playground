#include <iostream>

using namespace std;

class Polygon
{
protected:
    int width, height;

public:
    Polygon(int a, int b) : width(a), height(b) 
    {

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
    Rectangle(int a, int b) : Polygon(a, b)
    {

    }

    int area() const 
    {
        return width * height;
    }
};

class Triangle : public Polygon
{
public:
    Triangle(int a, int b) : Polygon(a, b)
    {

    }

    int area() const 
    {
        return width * height / 2;
    }
};

int main()
{
    Polygon * ppoly1 = new Rectangle(10, 3);
    Polygon * ppoly2 = new Triangle(10, 3);

    ppoly1->printArea();
    ppoly2->printArea();

    delete ppoly1;
    delete ppoly2;

    return 0;
}