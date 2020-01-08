#include <vector>
#include <string>
#include <functional>
#include <iostream>

using namespace std;

int main()
{
    string str1 = "Hello";
    string str2 = "World";

    vector<reference_wrapper<string>> vec{ ref(str1) };
    vec.push_back(ref(str2));

    vec[1].get() += "!";

    cout << str1 << " " << str2 << endl;

    return 0;
}