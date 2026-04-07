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
void logTransaction(int accNo, char type[], float amount) {
    FILE *fp = fopen("transactions.txt", "a");

    if (fp == NULL) {
        printf("Error opening transaction file\n");
        return;
    }

    fprintf(fp, "%d %s %.2f\n", accNo, type, amount);

    fclose(fp);
}
void viewTransactions(int accNo) {
    FILE *fp = fopen("transactions.txt", "r");

    if (fp == NULL) {
        printf("No transaction history found.\n");
        return;
    }

    int fileAccNo;
    char type[20];
    float amount;
    int found = 0;

    printf("\n📜 Transaction History:\n");

    while (fscanf(fp, "%d %s %f", &fileAccNo, type, &amount) != EOF) {
        if (fileAccNo == accNo) {
            printf("%s ₹%.2f\n", type, amount);
            found = 1;
        }
    }

    if (!found) {
        printf("No transactions for this account.\n");
    }

    fclose(fp);
}