#include <iostream>

using namespace std;

class Dog
{
public:
    virtual void bark() { cout << "Woof!" << endl; }
    virtual void eat() { cout << "the dog ate!" << endl; }
};

class Cat
{
public:
    virtual void mew() { cout << "Mewww!" << endl; }
    virtual void eat() { cout << "the cat ate!" << endl; }
};

class DogCat : public Dog, public Cat
{

};

int main()
{
    DogCat myDogCat;
    //myDogCat.eat(); // error! ambiguous access of 'eat'
    //solution
    dynamic_cast<Dog&>(myDogCat).eat();
    myDogCat.Cat::eat();

    return 0;
}