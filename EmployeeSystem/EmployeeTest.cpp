#include <iostream>
#include "Employee.h"

using namespace std;
using namespace Records;


// the code won't compile because of main function. 
// remove this main or change its name
int main()
{
    cout << "Testing the Employee class." << endl;
    auto emp = make_unique<Employee>();
    emp->setFirstName("John");
    emp->setLastName("Doe");
    emp->setEmployeeNumber(71);
    emp->setSalary(50000);
    emp->promote();
    emp->promote(50);
    emp->hire();
    emp->display();

    return 0;
}

