#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> stringVector(10, "Hello");

    for (auto it = begin(stringVector); it != end(stringVector); ++it) {
        it->append(" there");
    }

    /*
    for (auto& str : stringVector) {
        str.append(" there");
    }
    */

    return 0;
}