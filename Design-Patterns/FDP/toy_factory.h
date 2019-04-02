#ifndef __TOY_FACTORY_H__
#define __TOY_FACTORY_H__

#include "object.h"

class ToyFactory
{
public:
    static Toy * createToy(int type)
    {
        Toy *toy = nullptr;

        switch (type)
        {
            case 1:
            {
                toy = new Car;
                break;
            }
            case 2:
            {
                toy = new Bike;
                break;
            }
            case 3:
            {
                toy = new Plane;
                break;
            }
            default:
            {
                cout << "invalid toy type, please re-enter type" << endl;
                return nullptr;
            }
        }

        toy->prepareParts();
        toy->combineParts();
        toy->assembleParts();
        toy->applyLabel();
        toy->showProduct();

        return toy;
    }
};

#endif // __TOY_FACTORY_H__