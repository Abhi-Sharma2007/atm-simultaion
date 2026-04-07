#include "account.h"

void deposit(Account *acc, float amt) {
    acc->balance += amt;
}

int withdraw(Account *acc, float amt) {
    if (amt > acc->balance)
        return 0;
    acc->balance -= amt;
    return 1;
}
