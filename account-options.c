//
// Created by ryan on 6/20/26.
//

#include <stdio.h>
#include <stdlib.h>
#include "account-options.h"
#include "userlogin.h"


int checkingBalance[] = {854, 2010, 5312, 6910};
int savingsBalance[] = {1650, 5600, 10550, 11600};
char userOption;
signed short int transaction;
//signed short int transactionCount;


#define ACCOUNT_SELECT "Press 1 for checking account\nPress 2 for savings account\nPress 3 to go back\n"
#define AMOUNT_PROMPT "Amount: "
#define CHECKING_ACCOUNT_SELECTION "Checking account selected"
#define CURRENT_CHECKING_BALANCE "Your checking balance is $%d\n"
#define CURRENT_SAVINGS_BALANCE "Your savings balance is $%d\n"
#define DEPOSITED_AMOUNT "You deposited $%d\n"
#define INSUFFICIENT_FUNDS "Not enough money"
#define INVALID_SELECTION "Invalid Option"
#define OPTION_PROMPT "Option: "
#define SAVINGS_ACCOUNT_SELECTION "Savings account selected"
//#define TRANSACTION_LIMIT "Transaction limit reached"
#define TRANSFERRED_AMOUNT "You transferred $%d\n"
#define WAIT_FOR_INPUT_ACCOUNT "Press enter to continue"
#define WITHDRAWN_AMOUNT "You withdrew $%d\n"



// TODO Make checking and savings accounts global or prevent from having local variables erased: Done(Might look into better implementation in the future)
// TODO Add fast cash

 void deposit(void) {

        puts(ACCOUNT_SELECT);
        printf(OPTION_PROMPT);
        userOption = getchar(); // Get user option input

        switch (userOption) {

            case '1':
                system("cls");
                puts(CHECKING_ACCOUNT_SELECTION);
                puts("Enter how much you want to deposit into your checking account?");
                printf(AMOUNT_PROMPT);
                scanf("%3d", &transaction);

                transactionValidation();

                checkingBalance[userIndex] += transaction;

                printf(DEPOSITED_AMOUNT, transaction);
                printf(CURRENT_CHECKING_BALANCE, checkingBalance[userIndex]);

                puts(WAIT_FOR_INPUT_ACCOUNT);
                getchar(); // Flush input buffer
                getchar(); // Wait for user to press enter.
                system("cls");
                userIndex = 0; // Reset index to default value to prevent the next user from accessing the incorrect checking and savings account.
                login();
                //transactionCount += 1;
                //break;

            case '2':
                system("cls");
                puts(SAVINGS_ACCOUNT_SELECTION);
                puts("Enter how much you want to deposit into your savings account?");
                printf(AMOUNT_PROMPT);
                scanf("%3d", &transaction);

                transactionValidation();

                savingsBalance[userIndex] += transaction;

                printf(DEPOSITED_AMOUNT, transaction);
                printf(CURRENT_SAVINGS_BALANCE, savingsBalance[userIndex]);
                puts(WAIT_FOR_INPUT_ACCOUNT);
                getchar(); // Flush input buffer
                getchar(); // Wait for user to press enter.
                system("cls");
                userIndex = 0; // Reset index to default value to prevent the next user from accessing the incorrect checking and savings account.
                login();
                //transactionCount += 1;
                //break;

            case '3':
                system("cls");
                getchar();  // Flush input buffer to prevent newline bug
                transactionOption();

            default:
                puts(INVALID_SELECTION);
                puts(WAIT_FOR_INPUT_ACCOUNT);
                getchar();  // Flush input buffer to prevent newline bug
                getchar(); // Wait for user to press enter.
                system("cls");
                deposit();
        }
}


void withdraw(void) {

        puts(ACCOUNT_SELECT);
        printf(OPTION_PROMPT);
        userOption = getchar(); // Get user option input

        switch (userOption) {

            case '1':
                system("cls");
                puts(CHECKING_ACCOUNT_SELECTION);
                puts("Enter how much you want to withdraw from your checking account?");
                printf(AMOUNT_PROMPT);
                scanf("%3d", &transaction);

                transactionValidation();
                checkingOverdraftPrevention();

                checkingBalance[userIndex] -= transaction;

                printf(WITHDRAWN_AMOUNT, transaction);
                printf(CURRENT_CHECKING_BALANCE, checkingBalance[userIndex]);
                puts(WAIT_FOR_INPUT_ACCOUNT);
                getchar(); // Flush input buffer

                getchar(); // Wait for user to press enter.;
                system("cls");
                userIndex = 0; // Reset index to default value to prevent the next user from accessing the incorrect checking and savings account.
                login();
                //transactionCount += 1;
                //break;

            case '2':
                system("cls");
                puts(SAVINGS_ACCOUNT_SELECTION);

                puts("Enter how much you want to withdraw from your savings account?");
                printf(AMOUNT_PROMPT);
                scanf("%3d", &transaction);

                transactionValidation();
                savingsOverdraftPrevention();

                savingsBalance[userIndex] -= transaction;

                printf(WITHDRAWN_AMOUNT, transaction);
                printf(CURRENT_SAVINGS_BALANCE, savingsBalance[userIndex]);
                puts(WAIT_FOR_INPUT_ACCOUNT);
                getchar(); // Flush input buffer

                getchar(); // Wait for user to press enter.
                system("cls");
                userIndex = 0; // Reset index to default value to prevent the next user from accessing the incorrect checking and savings account.
                login();
                //transactionCount += 1;
                //break;

            case '3':
                system("cls");
                getchar();  // Flush input buffer to prevent newline bug
                transactionOption();

            default:
                puts(INVALID_SELECTION);
                puts(WAIT_FOR_INPUT_ACCOUNT);
                getchar();  // Flush input buffer to prevent newline bug
                getchar(); // Wait for user to press enter.
                system("cls");
                withdraw();
        }
}


void balance(void) {

        puts(ACCOUNT_SELECT);
        printf(OPTION_PROMPT);
        userOption = getchar(); // Get user option input

        switch (userOption) {

            case '1':
                system("cls");
                puts(CHECKING_ACCOUNT_SELECTION);
                printf(CURRENT_CHECKING_BALANCE, checkingBalance[userIndex]);
                puts(WAIT_FOR_INPUT_ACCOUNT);
                getchar();  // Flush input buffer to prevent newline bug
                getchar(); // Wait for user to press enter.
                system("cls");
                userIndex = 0; // Reset index to default value to prevent the next user from accessing the incorrect checking and savings account.
                login();
                //transactionCount += 1;
                //break;

            case '2':
                system("cls");
                puts(SAVINGS_ACCOUNT_SELECTION);
                printf(CURRENT_SAVINGS_BALANCE, savingsBalance[userIndex]);
                puts(WAIT_FOR_INPUT_ACCOUNT);
                getchar();  // Flush input buffer to prevent newline bug
                getchar(); // Wait for user to press enter.
                system("cls");
                userIndex = 0; // Reset index to default value to prevent the next user from accessing the incorrect checking and savings account.
                login();
                //transactionCount += 1;
                //break;

            case '3':
                system("cls");
                getchar();  // Flush input buffer to prevent newline bug
                transactionOption();

            default:
                puts(INVALID_SELECTION);
                puts(WAIT_FOR_INPUT_ACCOUNT);
                getchar();  // Flush input buffer to prevent newline bug
                getchar(); // Wait for user to press enter.
                system("cls");
                balance();
        }
}


void transfer(void) {

        puts(ACCOUNT_SELECT);
        printf(OPTION_PROMPT);
        userOption = getchar(); // Get user option input

        switch (userOption) {

            case '1':
                system("cls");
                puts(CHECKING_ACCOUNT_SELECTION);
                puts("How much do you want to transfer from this account to the savings account?");
                printf(AMOUNT_PROMPT);
                scanf("%3d", &transaction);

                transactionValidation();
                checkingOverdraftPrevention();

                checkingBalance[userIndex] -= transaction;
                savingsBalance[userIndex] += transaction;

                printf(TRANSFERRED_AMOUNT, transaction);
                printf(CURRENT_SAVINGS_BALANCE, savingsBalance[userIndex]);
                printf(CURRENT_CHECKING_BALANCE, checkingBalance[userIndex]);
                puts(WAIT_FOR_INPUT_ACCOUNT);
                getchar();  // Flush input buffer to prevent newline bug
                getchar(); // Wait for user to press enter.
                system("cls");
                userIndex = 0; // Reset index to default value to prevent the next user from accessing the incorrect checking and savings account.
                login();
                //transactionCount += 1;

            case '2':
                system("cls");
                puts(SAVINGS_ACCOUNT_SELECTION);
                puts("How much do you want to transfer from this account to the checking account?");
                printf(AMOUNT_PROMPT);
                scanf("%3d", &transaction);

                transactionValidation();
                savingsOverdraftPrevention();

                savingsBalance[userIndex] -= transaction;
                checkingBalance[userIndex] += transaction;

                printf(TRANSFERRED_AMOUNT, transaction);
                printf(CURRENT_CHECKING_BALANCE, checkingBalance[userIndex]);
                printf(CURRENT_SAVINGS_BALANCE, savingsBalance[userIndex]);
                puts(WAIT_FOR_INPUT_ACCOUNT);
                getchar();  // Flush input buffer to prevent newline bug
                getchar(); // Wait for user to press enter.
                system("cls");
                userIndex = 0; // Reset index to default value to prevent the next user from accessing the incorrect checking and savings account.
                login();
                //transactionCount += 1;

            case '3':
                system("cls");
                getchar();  // Flush input buffer to prevent newline bug
                transactionOption();

            default:
                puts(INVALID_SELECTION);
                puts(WAIT_FOR_INPUT_ACCOUNT);
                getchar();  // Flush input buffer to prevent newline bug
                getchar(); // Wait for user to press enter.
                system("cls");
                transfer();
        }
}

// Prevent user from entering 0, a negative balance, or a balance above the transaction limit.
int transactionValidation(void) {
     if (transaction < 1 || transaction > 800) {    // Having 0 excluded also prevents letters from being entered.
        puts("Invalid amount\n");
        transactionOption();

    }
    return 0;
}


// Prevent overdraft for both accounts
int checkingOverdraftPrevention(void) {
    if (transaction > checkingBalance[userIndex]) {
        puts(INSUFFICIENT_FUNDS);
        transactionOption();
    }
    return 0;
}

int savingsOverdraftPrevention(void) {
    if (transaction > savingsBalance[userIndex]) {
        puts(INSUFFICIENT_FUNDS);
        transactionOption();
    }
    return 0;
}


// Transaction selection menu
void transactionOption(void) {

    do {
        puts("Enter a number from the list to select an option: ");

        printf("\n 1. Deposit"
         "\n 2. Withdraw \n 3. Balance"
         "\n 4. Transfer \n 5. Logout \n");

        printf(OPTION_PROMPT);
        char userOption = getchar(); // Get user option input

        /*if (transactionCount >=3) {
            puts(transactionLimit);
            transactionCount = 0; // Reset transaction count so that the next user isn't logged out after the first transaction
            login();
        }*/


        switch (userOption) {
            case '1':
                system("cls");
                getchar();  // Flush input buffer to prevent newline bug
                deposit();
                break;

            case '2':
               system("cls");
               getchar();  // Flush input buffer to prevent newline bug
               withdraw();
                break;

            case '3':
               system("cls");;
               getchar();  // Flush input buffer to prevent newline bug
               balance();
                break;

            case '4':
                system("cls");
                getchar();  // Flush input buffer to prevent newline bug
                transfer();
                break;

            case '5':
                system("cls");
                puts("Logged out");
                userIndex = 0; // Reset index to default value to prevent the next user from accessing the incorrect checking and savings account.
                login();

            default:
                puts(INVALID_SELECTION);
                puts(WAIT_FOR_INPUT_ACCOUNT);
                getchar();  // Flush input buffer to prevent newline bug
                getchar(); // Wait for user to press enter.
                system("cls");
                transactionOption();
        }
    } while (getchar() != '5');
}