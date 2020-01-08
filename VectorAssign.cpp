#include <vector>

using namespace std;

int main()
{
    vector<int> intVector(10);
    intVector.assign(5, 100);

    intVector.assign({1, 2, 3, 4});

    vector<int> vectorOne(10);
    vector<int> vectorTwo(5, 100);

    vectorOne.swap(vectorTwo);

    return 0;
}