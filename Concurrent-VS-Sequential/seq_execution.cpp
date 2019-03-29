#include <array>
#include "common.h"

std::array<int, 10> _finalArr;

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
    int first = oper.firstOperand;
    int second = oper.secondOperand;
    int op = oper.oper;

    switch (op)
    {
        case 0:
            _finalArr[first] += _finalArr[second];
            break;
        case 1:
        {
            std::swap(_finalArr[first], _finalArr[second]);
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

    std::vector<operations> opVec(read_operations_file(argv[1]));

    for (auto& v : opVec)
    {
        doOperation(v);
    }

    printFinalArr();

    return 0;
}
