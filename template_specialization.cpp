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

int main()
{
    vector<int> vecInt = {1, 2, 3, 4, 5};
    vector<double> vecDouble = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector<string> vecString = {"abc"};

    cout << addAll(vecInt) << endl;
    cout << addAll(vecDouble) << endl;
    cout << addAll(vecString) << endl;

    return 0;
}