#ifndef __BASE_H__
#define __BASE_H__

#include <iostream>
#include <array>
#include <vector>

class Operations
{
public:
    void setOperation(int first, int second, int op);
    int getFirstOperand() const {return _firstOperand;};
    int getSecondOperand() const {return _secondOperand;};
    int getOperator() const {return _oper;};
private:
    int _firstOperand, _secondOperand, _oper;
};

class Base
{
public:
    Base();
    void resetList();
    void printList();
    std::vector<Operations> readOperationsFile();

    int generateRandomOperator();
    int generateRandomId(int max);
    void generateCommand(int numbers);

    bool isFileExists(const std::string &name);

    void doSequentially();
    void doConcurrently();

private:

    std::array<int, 10> _list;
    void doOperationSeq(Operations oper);
};

#endif // __BASE_H__