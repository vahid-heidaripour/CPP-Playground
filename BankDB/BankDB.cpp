#include "BankDB.h"
#include <utility>
#include <stdexcept>

using namespace std;

bool BankDB::addAccount(const BankAccount &account)
{
    auto res = mAccounts.emplace(account.getAcctNum(), account);

    return res.second;
}

void BankDB::deleteAccount(int acctNum)
{
    mAccounts.erase(acctNum);
}

BankAccount& BankDB::findAccount(int acctNum)
{
    auto it = mAccounts.find(acctNum);

    if (it == end(mAccounts)) {
        throw out_of_range("No account with that number.");
    }

    return it->second;
}

BankAccount& BankDB::findAccount(std::string_view name)
{
    for (auto& [acctNum, account] : mAccounts) {
        if (account.getClientName() == name) {
            return account; //found it
        }
    }

    throw out_of_range("No account with that name.");
}

void BankDB::mergeDatabase(BankDB &db)
{
    mAccounts.merge(db.mAccounts);

    db.mAccounts.clear();
}