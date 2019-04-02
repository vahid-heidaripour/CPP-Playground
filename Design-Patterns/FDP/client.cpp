#include "toy_factory.h"

int main()
{
    int type;

    while (1)
    {
        cout << endl << "Enter type or Zero for exit" << endl;
        cin >> type;
        if (!type)
            break;

        Toy *v = ToyFactory::createToy(type);
        if (v)
        {
            v->showProduct();
            delete v;
        }
    }

    cout << "Exit..." << endl;

    return 0;
}