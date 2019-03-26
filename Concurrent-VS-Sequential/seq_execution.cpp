#include <iostream>
#include <array>
#include <fstream>
#include <vector>

std::array<int, 10> _finalArr;

struct operations
{
    int f;
    int s;
    int o;
};

std::vector<operations> _opVec;

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

void doOperation(operations oper)
{
    int first = oper.f;
    int second = oper.s;
    int op = oper.o;

    switch (op)
    {
        case 0:
            _finalArr[first] += _finalArr[second];
            break;
        case 1:
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

    // 0 is add and 1 is swap
    int first, second, op;

    while (infile >> first >> second >> op)
    {
        operations operation;
        operation.f = first;
        operation.s = second;
        operation.o = op;

        _opVec.push_back(operation);
    }

    for (auto& v : _opVec)
    {
        doOperation(v);
    }


    infile.close();

    printFinalArr();

    return 0;
}
