#include <iostream>

using namespace std;

class Gregarious
{
public:
    virtual void talk() {
        cout << "Gregarious says hi!" << endl;
    }
};

class Shy : public Gregarious
{
protected:
    virtual void talk() override {
        cout << "Shy says hello!" << endl;
    }
};

int main()
{
    Shy myShy;
    //myShy.talk(); //error! 'Shy::talk': cannot access protected member declared in class 'Shy'
    //how to solve?
    Gregarious& ref = myShy;
    ref.talk();

    return 0;
}