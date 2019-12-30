#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records {
    const int kFirstEmployeeNumber = 1000;

    class Database {
    public:
        Employee& addEmployee(const std::string& firstName,
                const std::string& lastName);
        Employee& getEmployee(int employeeNumber);
        Employee& getEmployee(const std::string& firstName,
                std::string& lastName);

        void displayAll() const;
        void displayCurrent() const;
        void displayFormer() const;

    private:
        std::vector<Employee> mEmployees;
        int mNextEmployeeNumber = kFirstEmployeeNumber;
    };
}

#endif //__DATABASE_H__
