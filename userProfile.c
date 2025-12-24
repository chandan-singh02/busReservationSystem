#include <stdio.h>
#include <string.h>
#include "busBookingProfile.c"

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

    printf("\nLogin successful. Welcome, %s\n", username);
    return 1;
}

// THIS is userMenu
void userMenu()
{
    int userMenuOption;

    while (1)
    {
        printf("\n<-------------------- User Dashboard Page -------------------- >\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Check Bus Status\n");
        printf("4. Payment\n");
        printf("5. Logout\n");

        printf("Select an option: ");
        scanf("%d", &userMenuOption);

        if (userMenuOption == 1)
        {
            printf("\nBook Ticket selected\n");
            bookBusTicket();
        }
        else if (userMenuOption == 2)
        {
            printf("\nCancel Ticket selected\n");
            cancelBusTicket();
        }
        else if (userMenuOption == 3)
        {
            printf("\nCheck Bus Status selected\n");
            checkBusStatus();
        }
        else if (userMenuOption == 4)
        {
            printf("\nPayment selected\n");
            payment();
        }
        else if (userMenuOption == 5)
        {
            printf("\nLogging out...\n");
            printf("\nLogged out successfull!\n");
            break;
        }
        else
        {
            printf("Invalid option. Please try again.\n");
        }
    }
}
