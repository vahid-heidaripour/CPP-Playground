#include "BankDB.h"
#include <iostream>

using namespace std;

int main()
{
    BankDB db;

    db.addAccount(BankAccount(100, "Vahid H."));
    db.addAccount(BankAccount(200, "Mahdieh S."));

    try {
        auto& acct = db.findAccount(100);
        cout << "Found account 100" << endl;
        acct.setClientName("Vahid Heidaripour");

        auto& acct2 = db.findAccount("Mahdieh S.");
        cout << "Found account of Mahdieh S." << endl;

        auto& acct3 = db.findAccount(1000);
    } catch (const out_of_range& caughtException) {
        cout << "Unable to find account: " << caughtException.what() << endl;
    }

    return 0;
}