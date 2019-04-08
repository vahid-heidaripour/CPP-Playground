// Some time we have to specialize template for a particular data type
// We can specialize both 'function' and 'class' template

#include <iostream>
#include <vector>
#include <sstream>

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

template <>
std::string addAll(std::vector<std::string> list)
{
    int count = 0;

    for (const string& elem : list)
    {
        for (const char& chr : elem)
        {
            count += chr;
        }
    }

    ostringstream ostr;
    ostr << count;
    string strCount = ostr.str();

    return strCount;
}