#include <iostream>
#include <fstream>
#include "base.h"

Base::Base()
{
    resetList();
    generateCommand(10);
    readOperationsFile();
}

void Operations::setOperation(int first, int second, int op)
{
    _firstOperand = first;
    _secondOperand = second;
    _oper = op;
}

void Base::resetList()
{
    _list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
}

void Base::printList()
{
    for (auto l : _list)
        std::cout << l << " ";
    std::cout << std::endl;
}

std::vector<Operations> Base::readOperationsFile()
{
    std::vector<Operations> resVec;
    std::ifstream infile;
    infile.open("command_list");

    int first, second, op;
    while (infile >> first >> second >> op)
    {
        Operations oper;
        oper.setOperation(first, second, op);
        resVec.push_back(oper);
    }

    infile.close();

    return resVec;
}

int Base::generateRandomOperator()
{
    int coin = rand() % 2 + 1;
            //uniform_dist(std::Random::get(1, 2));
    if (coin == 1)
        return 0;
    else
        return 1;
}

int Base::generateRandomId(int max)
{
    return rand() % max;
    //uniform_dist(std::Random::get(0, max));
}

void Base::generateCommand(int numbers)
{
    if (!isFileExists("command_list"))
    {
        std::ofstream outfile;
        outfile.open("command_list");

        for (int i = 0; i < numbers; ++i) {
            int firstRandomId = generateRandomId(9);
            int secondRandomId = generateRandomId(9);
            int randomOperator = generateRandomOperator();

            outfile << firstRandomId << " " << secondRandomId << " " << randomOperator << std::endl;
        }

        outfile.close();
    }
}

bool Base::isFileExists(const std::string &name)
{
    std::ifstream f(name.c_str());
    return f.good();
}

void Base::doSequentially()
{
    std::vector<Operations> opVec = readOperationsFile();

    for (auto& v : opVec)
    {
        doOperationSeq(v);
    }
}

void Base::doConcurrently()
{

}

void Base::doOperationSeq(Operations oper)
{
    int first = oper.getFirstOperand();
    int second = oper.getSecondOperand();
    int op = oper.getOperator();

    switch (op)
    {
        case 0:
            _list[first] += _list[second];
            break;
        case 1:
        {
            std::swap(_list[first], _list[second]);
        }
            break;
        default:
            break;
    }
}