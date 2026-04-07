#include <stdio.h>
#include "file_ops.h"
#include "account.h"
int readAccount(int accNo, Account *acc) {
    FILE *fp = fopen("accounts.txt", "r");

    while (fscanf(fp, "%d %s %d %f",
        &acc->accNo, acc->name, &acc->pin, &acc->balance) != EOF) {

        if (acc->accNo == accNo) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void updateAccount(Account updated) {
    FILE *fp = fopen("accounts.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    Account acc;

    while (fscanf(fp, "%d %s %d %f",
        &acc.accNo, acc.name, &acc.pin, &acc.balance) != EOF) {

        if (acc.accNo == updated.accNo)
            acc = updated;

        fprintf(temp, "%d %s %d %.2f\n",
            acc.accNo, acc.name, acc.pin, acc.balance);
    }

    fclose(fp);
    fclose(temp);
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}
