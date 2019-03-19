#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <chrono>

class bank_account
{
    double balance;
    std::string name;
    std::mutex m;

public:
    bank_account() {};

    bank_account(double _balance, std::string _name) : balance(_balance), name(_name) {}

    bank_account(const bank_account&) = delete;
    bank_account &operator=(const bank_account &) = delete;
};

int main(int argc, char *argv[])
{
    return 0;
}
