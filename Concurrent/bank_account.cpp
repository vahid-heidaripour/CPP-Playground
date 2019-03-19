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

    void withdraw(double amount)
    {
        std::lock_guard<std::mutex> lg(m);
        balance += amount;
    }

    void deposite(double amount)
    {
        std::lock_guard<std::mutex> lg(m);
        balance += amount;
    }

    void transfer(bank_account& from, bank_account& to, double amount)
    {
        std::cout << std::this_thread::get_id() << " hold the lock for both mutex \n";

        std::unique_lock<std::mutex> ul_1(from.m, std::defer_lock);
        std::unique_lock<std::mutex> ul_2(to.m, std::defer_lock);

        std::lock(ul_1, ul_2);

        from.balance -= amount;
        to.balance += amount;
        std::cout << "transfer to - " << to.name << "  from - " << from.name << "  end \n";
    }
};

int main(int argc, char *argv[])
{
    bank_account account;

    bank_account account_1(1000, "James");
    bank_account account_2(1000, "Theo");


    std::thread thread_1(&bank_account::transfer, &account, std::ref(account_1), std::ref(account_2), 100);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread thread_2(&bank_account::transfer, &account, std::ref(account_2), std::ref(account_1), 100);

    thread_1.join();
    thread_2.join();

    return 0;
}
