#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50


typedef struct {
    int accNumber;
    char name[MAX_NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void createAccount(int accNumber, char name[], float initialBalance) {
    if (numAccounts < MAX_ACCOUNTS) {
        accounts[numAccounts].accNumber = accNumber;
        strcpy(accounts[numAccounts].name, name);
        accounts[numAccounts].balance = initialBalance;
        numAccounts++;
        printf("Account created successfully.\n");
    } else {
        printf("Cannot create account. Maximum number of accounts reached.\n");
    }
}

void deposit(int accNumber, float amount) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accNumber == accNumber) {
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw(int accNumber, float amount) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accNumber == accNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient funds.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void checkBalance(int accNumber) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accNumber == accNumber) {
            printf("Balance for account %d (%s): %.2f\n", accounts[i].accNumber, accounts[i].name, accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    int choice, accNumber;
    float amount;
    char name[MAX_NAME_LENGTH];

    do {
        printf("\nBanking System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &accNumber);
                printf("Enter account holder name: ");
                scanf("%s", name);
                printf("Enter initial balance: ");
                scanf("%f", &amount);
                createAccount(accNumber, name, amount);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &accNumber);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(accNumber, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &accNumber);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(accNumber, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &accNumber);
                checkBalance(accNumber);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

