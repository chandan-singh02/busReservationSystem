#include <stdio.h>
#include <string.h>
// #include "userProfile.h"
int userLogin();
void userMenu();

// THIS IS USER LOGIN
int userLogin()
{
    char username[50], password[50];

    printf("\n<-------------User Login Page------------->\n");

    printf("Please enter your username: ");
    scanf("%s", username);

    printf("Please enter your password: ");
    scanf("%s", password);

    if (strlen(username) < 3)
    {
        printf("Username must be at least 3 characters long.\n");
        return 0;
    }

    if (strlen(password) < 6)
    {
        printf("Password must be at least 6 characters long.\n");
        return 0;
    }

    printf("Login successful. Welcome, %s\n", username);
    return 1;
}

// THIS is userMenu
void userMenu()
{
    int userMenuOption;

    while (1)
    {
        printf("\n<------------- User Dashboard ------------->\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Check Bus Status\n");
        printf("4. Logout\n");

        printf("Select an option: ");
        scanf("%d", &userMenuOption);

        if (userMenuOption == 1)
        {
            printf("Book Ticket selected\n");
            bookBusTicket();
        }
        else if (userMenuOption == 2)
        {
            printf("Cancel Ticket selected\n");
        }
        else if (userMenuOption == 3)
        {
            printf("Check Bus Status selected\n");
        }
        else if (userMenuOption == 4)
        {
            printf("Logging out...\n");
            break;
        }
        else
        {
            printf("Invalid option. Please try again.\n");
        }
    }
}
