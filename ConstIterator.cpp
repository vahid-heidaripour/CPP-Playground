#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<string> stringVector(10, "Hello");
    for (auto iter = cbegin(stringVector); iter != cend(stringVector); ++iter) {
        cout << *iter << endl;
    }

    cout << "-------------------------------------------------------" << endl;

    for (const auto& element : stringVector) {
        cout << element << endl;
    }
}