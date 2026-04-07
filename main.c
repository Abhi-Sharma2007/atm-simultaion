#include <stdio.h>
#include "auth.h"
#include "account.h"
#include "file_ops.h"

int main() {
    int accNo, pin, choice;
    float amount;
    Account acc;

    printf("===== ATM MACHINE =====\n");

    // 🔐 Login
    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    if (!authenticateUser(accNo, pin)) {
        printf("❌ Invalid Account Number or PIN\n");
        return 0;
    }

    // Load account data
    if (!readAccount(accNo, &acc)) {
        printf("Account not found!\n");
        return 0;
    }

    printf("\n✅ Login Successful!\n");

    // 🎯 Menu
    do {
        printf("\n===== MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("💰 Balance: %.2f\n", acc.balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&acc, amount);
                updateAccount(acc);
                printf("✅ Deposit successful\n");
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (withdraw(&acc, amount)) {
                    updateAccount(acc);
                    printf("✅ Withdrawal successful\n");
                } else {
                    printf("❌ Insufficient balance\n");
                }
                break;

            case 4:
                printf("Thank you for using ATM!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}