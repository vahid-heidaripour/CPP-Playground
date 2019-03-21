#include <iostream>
#include <array>
#include <fstream>

std::array<unsigned long long int, 10> _finalArr;

void initFinalArray()
{
    _finalArr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
}

void printFinalArr()
{
    for (auto& f : _finalArr)
        std::cout << f << " ";
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "usage: " << argv[0] << " filename" << std::endl;
        return 1;
    }

    initFinalArray();

    std::ifstream infile;
    infile.open(argv[1]);

    int first, second;
    char op;

    while (infile >> first >> second >> op)
    {
        switch (op)
        {
            case '+':
                _finalArr[first] += _finalArr[second];
                break;
            case '#':
            {
                auto temp = _finalArr[first];
                _finalArr[first] = _finalArr[second];
                _finalArr[second] = temp;
            }
                break;
            default:
                break;
        }
    }

    infile.close();

    printFinalArr();

    return 0;
}
