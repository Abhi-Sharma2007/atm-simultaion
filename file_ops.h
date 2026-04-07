#ifndef FILE_OPS_H
#define FILE_OPS_H

#include "account.h"

int readAccount(int accNo, Account *acc);
void updateAccount(Account updated);

void logTransaction(int accNo, char type[], float amount);
void viewTransactions(int accNo);

#endif