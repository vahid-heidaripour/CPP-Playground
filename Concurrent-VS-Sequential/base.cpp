#include <iostream>
#include <fstream>
#include <chrono>
#include "base.h"
#include "thread_pool_with_local_work_queue.h"
#include "simple_thread_pool.h"

Base::Base()
{
    resetList();
    generateCommand(10);
    printList();
}

void Operations::setOperation(int first, int second, int op, int seqNo)
{
    _firstOperand = first;
    _secondOperand = second;
    _oper = op;
    _seqNo = seqNo;
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

std::queue<Operations> Base::readOperationsFile()
{
    std::queue<Operations> resQueue;
    std::ifstream infile;
    infile.open("command_list");

    int i = 0;
    int first, second, op;
    while (infile >> first >> second >> op)
    {
        Operations oper;
        oper.setOperation(first, second, op, i++);
        resQueue.push(oper);
    }

    infile.close();

    return resQueue;
}

int Base::generateRandomOperator()
{
    int coin = rand() % 2 + 1;
    if (coin == 1)
        return 0;
    else
        return 1;
}

int Base::generateRandomId(int max)
{
    return rand() % max;
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
    std::queue<Operations> opQueue = readOperationsFile();

    while (!opQueue.empty())
    {
        doOperation(opQueue.front());
        opQueue.pop();
    }
}

void Base::doOperation(Operations oper)
{
    int first = oper.getFirstOperand();
    int second = oper.getSecondOperand();
    int op = oper.getOperator();

    switch (op)
    {
        case 0:
            _list[first] += _list[second];
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            break;
        case 1:
        {
            std::swap(_list[first], _list[second]);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
            break;
        default:
            break;
    }
}

void Base::doConcurrently()
{
    thread_pool pool;

    std::queue<Operations> opQueue = readOperationsFile();
    while (!opQueue.empty())
    {
        Operations operation = opQueue.front();
        pool.submit([=]{
            doOperation(operation);
        });
        opQueue.pop();
    }
}