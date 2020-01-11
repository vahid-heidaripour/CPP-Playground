#include <algorithm>
#include <iostream>
#include <vector>
#include <execution>

using namespace std;

template<typename Container>
void populateContainer(Container& cont)
{
    int num;

    while (true) {
        cout << "Enter a number (0 to quit): ";
        cin >> num;
        if (num == 0) {
            break;
        }
        cont.push_back(num);
    }
}

int main()
{
    vector<int> myVector;
    populateContainer(myVector);

    cout << "Before sorting:" << endl;
    for (const auto& i : myVector) { cout << i << " "; }
    cout << endl;

    sort(std::execution::par, begin(myVector), end(myVector));

    cout << "After sorting:" << endl;
    for (const auto& i : myVector) { cout << i << " "; }
    cout << endl;

    return 0;
}
