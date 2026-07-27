#include <stdio.h>
#include <stdlib.h>
#include "userlogin.h"


/* ATM Simulation program text based version by Ryan Cannon
   Started on 6/18/26 and coded with CLion 2025.3.2, as well as Cxxdroid 5.6_arm64 when I wasn't at my desktop or laptop

*/


/* TODO:

   1. Add ascii animations for startup and transaction process: Still need to do.
   2. Add the ability to save user account info in a file
   2. Replace getchar, and scanf statements with fgets for better input handling. getchar() is used way too much.
   3. Rewrite and optimize the code further as needed

*/


int main(void) {

    system("cls");
    puts("ATM Simulator Windows version");
    puts("Copyright Ryan Mitchell Cannon 2026\n");
    puts("Press enter to continue");

    getchar(); // Wait for user to press enter.
    system("cls");

    login();
}