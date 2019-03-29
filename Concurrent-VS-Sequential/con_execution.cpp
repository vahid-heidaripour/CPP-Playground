#include <list>
#include "thread_pool_with_local_work_queue.h"

std::list<int> _finalList;

void initFinalList()
{
    _finalList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
}

void printFinalList()
{
    for (auto f : _finalList)
        std::cout << f << " ";
    std::cout << std::endl;
}

/*void doOperation(operations oper)
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
            auto temp = _finalArr[first];
            _finalArr[first] = _finalArr[second];
            _finalArr[second] = temp;
        }
            break;
        default:
            break;
    }
}*/

void doOperation(std::vector<operations> oper)
{
    thread_pool_with_local_work_queue pool;


}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "usage: " << argv[0] << " filename" << std::endl;
        return 1;
    }

    initFinalList();

    std::vector<operations> opVec(read_operations_file(argv[1]));

    // do operation

    printFinalList();

    return 0;
}