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
};

class Rectangle : public Polygon
{
public:
    int area() const
    { return width * height; }
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

    ppoly1->setValues(4, 6);
    ppoly2->setValues(4, 6);

    cout << rect.area() << endl;
    cout << trgl.area() << endl;
    
    return 0;
}

