#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printVector(const vector<T>& v)
{
    for (auto& element : v) {
        cout << element << " ";
    }
    cout << endl << "-------------------------------------------------" << endl;
}

int main()
{
    vector<int> vector1 = {1, 2, 3, 5};
    vector<int> vector2;

    vector1.insert(cbegin(vector1) + 3, 4);

    for (int i = 6; i <= 10; i++) {
        vector2.push_back(i);
    }

    printVector(vector1);
    printVector(vector2);

    vector1.insert(cend(vector1), cbegin(vector2), cend(vector2));
    printVector(vector1);

    vector1.erase(cbegin(vector1) + 1, cbegin(vector1) + 5);
    printVector(vector1);

    vector2.clear();

    vector2.insert(cbegin(vector2), 10, 100);

    vector2.pop_back();
    printVector(vector2);

    return 0;
}