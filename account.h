#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct {
    int accNo;
    char name[30];
    int pin;
    float balance;
} Account;

void deposit(Account *acc, float amt);
int withdraw(Account *acc, float amt);
#endif