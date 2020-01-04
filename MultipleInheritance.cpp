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
public:
	//another way to solve the problem is to have an eat() method here.
	void eat() override { Dog::eat(); }
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