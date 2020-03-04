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

    virtual int area() const
    {
        return 0;
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
    Polygon poly;
    Polygon * ppoly1 = &rect;
    Polygon * ppoly2 = &trgl;
    Polygon * ppoly3 = &poly;

    ppoly1->setValues(2, 10);
    ppoly2->setValues(2, 10);
    ppoly3->setValues(2, 10);

    cout << ppoly1->area() << endl;
    cout << ppoly2->area() << endl;
    cout << ppoly3->area() << endl;

    return 0;
}