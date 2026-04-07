#include <stdio.h>
#include "auth.h"
#include "account.h"
#include "file_ops.h"

int main() {
    int accNo, pin, choice;
    float amount;
    Account acc;

    printf("===== ATM MACHINE =====\n");

    // Login
    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    if (!authenticateUser(accNo, pin)) {
        printf("❌ Invalid Account Number or PIN\n");
        return 0;
    }

    // Load account details
    readAccount(accNo, &acc);

    printf("\n✅ Login Successful!\n");
    printf("Welcome %s!\n", acc.name);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("5. View Transactions\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("💰 Balance: ₹%.2f\n", acc.balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);

                deposit(&acc, amount);
                updateAccount(acc);
                logTransaction(acc.accNo, "DEPOSIT", amount);

                printf("₹%.2f deposited successfully!\n", amount);
                printf("New Balance: ₹%.2f\n", acc.balance);
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                if (withdraw(&acc, amount)) {
                    updateAccount(acc);
                    logTransaction(acc.accNo, "WITHDRAW", amount);

                    printf("₹%.2f withdrawn successfully!\n", amount);
                    printf("Remaining Balance: ₹%.2f\n", acc.balance);
                } else {
                    printf("❌ Insufficient balance! Transaction failed.\n");
                }
                break;

            case 4:
                printf("Thank you for using ATM!\n");
                break;

            case 5:
                viewTransactions(acc.accNo);
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}