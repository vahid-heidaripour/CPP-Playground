// Some time we have to specialize template for a particular data type
// We can specialize both 'function' and 'class' template

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T addAll(std::vector<T> list)
{
    T count = 0;

    for (auto& elem : list)
    {
        count += elem;
    }

    return count;
}