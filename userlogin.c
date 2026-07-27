//
// Created by ryan on 6/21/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "userlogin.h"
#include "account-options.h"

#define WAIT_FOR_INPUT_LOGIN


short int userIndex = 0; // Index for selecting accounts based on the logged-in user

void login(void) {

    char userLogin[22];  // Went with a 22-character limit since the SSA has a 21 letter length limit for surnames

    struct Customer {
        char *userName;
    };


    struct Customer customer1 = {.userName = "rwellman"};
    struct Customer customer2 = {.userName = "sdownings"};
    struct Customer customer3 = {.userName = "jdoe"};
    struct Customer customer4 = {.userName = "jsmith"};


    short int usernameAttempt = 0;


    while (usernameAttempt <= 3) {
        printf("Enter username: ");
        scanf("%22s", userLogin);

        // Using strcmp like this is the only way to properly compare usernames. "Strings" are a headache to work with in C.

        // Login for Richard Wellman
        if (strcmp(customer1.userName, userLogin) ==0) {
            system("cls");
            password();
        }

        // Login for Susan Downings
        else if (strcmp(customer2.userName, userLogin) ==0) {
            userIndex += 1;
            system("cls");
            password();
        }

        // Login for Jane Doe
        else if (strcmp(customer3.userName, userLogin) ==0){
            userIndex += 2;
            system("cls");
            password();
        }

        // Login for John Smith
        else if (strcmp(customer4.userName, userLogin) ==0) {
            userIndex += 3;
            system("cls");
            password();
        }

        // Exit program
        else if (strcmp("shutdown", userLogin) ==0 || strcmp("quit", userLogin) ==0 || strcmp("exit", userLogin) ==0) {
            // Prevent CMD from immediately closing May look into better implementation in future updates
            system("cls");
            puts("Goodbye");
            puts("Press enter to continue");
            getchar();  // Flush input buffer to prevent newline bug
            getchar(); // Wait for user to press enter.
            exit(0);
        }

        else {

            puts("User not found");
            puts("Press enter to continue");
            getchar();  // Flush input buffer to prevent newline bug
            getchar(); // Wait for user to press enter.
            system("cls");
            usernameAttempt += 1;

        }
    }
    
    // Display after failed username attempts
    puts("ATM restriction is now in place. This program will now close.\n");
    puts("Press enter to continue");
    getchar();  // Flush input buffer to prevent newline bug
    getchar(); // Wait for user to press enter.
    system("cls");

    exit(0);
}


void password(void) {

    char userPassword[16];

    struct Customer {
        char *fullName;
        char *password;
    };


    short int passwordAttempt = 0;

    struct Customer customer1 = {.fullName="Richard Wellman", .password = "cyan541"};
    struct Customer customer2 = {.fullName="Susan Downings", .password = "cats4123"};
    struct Customer customer3 = {.fullName="Jane Doe", .password = "Pass@123"};
    struct Customer customer4 = {.fullName="John Smith", .password = "kr0n0s"};


    while (passwordAttempt <= 3) {
        printf("Enter password: ");
        scanf("%16s", userPassword);

        if (strcmp(customer1.password, userPassword) ==0) {
            system("cls");
            printf("Hello %s\n", customer1.fullName);
            getchar();  // Flush input buffer to prevent newline bug
            transactionOption();


        }

        else if (strcmp(customer2.password, userPassword) ==0) {
            system("cls");
            printf("Hello %s\n", customer2.fullName);
            getchar();  // Flush input buffer to prevent newline bug
            transactionOption();

        }

        else if (strcmp(customer3.password, userPassword) ==0) {
            system("cls");
            printf("Hello %s\n", customer3.fullName);
            getchar();  // Flush input buffer to prevent newline bug
            transactionOption();

        }

        else if (strcmp(customer4.password, userPassword) ==0) {
            system("cls");
            printf("Hello %s\n", customer4.fullName);
            getchar();  // Flush input buffer to prevent newline bug
            transactionOption();

        }

        else {
            puts("Incorrect password");
            puts("Press enter to continue");
            getchar();  // Flush input buffer to prevent newline bug
            getchar(); // Wait for user to press enter.
            system("cls");
            passwordAttempt += 1;
        }
    }
}