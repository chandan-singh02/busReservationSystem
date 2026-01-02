#include <stdio.h>
#include <string.h>
#include "busBookingProfile.c"
#include "inputValidation.c"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

int userLogin();
void userMenu();
int verifyOTP();

char name[20];
char email[30];
char userName[20];
char password[20];
char address[40];
char mobileNumber[11];

int systemGenrateOTP = 889143;
int isSignUp = 0;

int verifyOTP()
{
    int attempts = 0;
    int otp = 0;

    printf("\nOTP sent to your registered number:%d\n", systemGenrateOTP);

    while (attempts < 3)
    {
        printf("Enter OTP to verify: ");
        scanf("%d", &otp);

        if (otp == systemGenrateOTP)
        {
            printf(GREEN "\nSignup successful! Please login.\n" RESET);
            return 1;
        }

        attempts++;

        if (attempts < 3)
        {
            printf(RED "Incorrect OTP! Attempts left: %d\n" RESET, 3 - attempts);
        }
    }

    printf(RED "OTP verification failed. Please signup again.\n" RESET);
    return 0;
}

// This for signup
int signUp()
{
    printf(CYAN "\nUSER SIGNUP PAGE\n" RESET);
    printf(CYAN "--------------------------------\n" RESET);

    while (1)
    {
        printf("Please enter your name       : ");
        scanf(" %[^\n]", name);

        if (isValidName(name))
            break;
    }

    while (1)
    {
        printf("please enter your username   : ");
        scanf("%s", &userName);

        if (isValidUsername(userName))
            break;
    }

    while (1)
    {
        printf("please enter your email      : ");
        scanf("%s", &email);

        if (isValidEmail(email))
            break;
    }

    while (1)
    {
        printf("please enter your address    : ");
        scanf(" %[^\n]", &address);

        if (isValidName(name))
            break;
    }

    while (1)
    {
        printf("please enter your mobileNo   : ");
        scanf("%s", &mobileNumber);

        if (isValidMobile(mobileNumber))
            break;
    }

    while (1)
    {
        printf("please enter your password   : ");
        scanf("%s", &password);

        if (isValidPassword(password))
            break;

        printf(RED "Password must contain at least 1 letter and 1 number.\n" RESET);
    }

    if (!verifyOTP())
    {
        return 0;
    }

    isSignUp = 1;
    return 1;
}

// THIS IS FOR USER LOGIN
int userLogin()
{
    char loginUsername[20], loginPassword[20];

    if (isSignUp == 0)
    {
        printf(RED "\nNo user found database. Please signup first!\n" RESET);
        return 0;
    }
    printf(CYAN "\nUSER LOGIN PAGE\n" RESET);
    printf(CYAN "--------------------------------\n" RESET);

    printf("Please enter your username: ");
    scanf("%s", &loginUsername);

    printf("Please enter your password: ");
    scanf("%s", &loginPassword);

    if (strcmp(loginUsername, userName) == 0 &&
        strcmp(loginPassword, password) == 0)
    {
        printf(GREEN "\nLogin successful. Welcome, %s\n" RESET, name);
        return 1;
    }
    else
    {
        printf(RED "\nInvalid username or password!\n" RESET);
        return 0;
    }
}

// THIS IS FOR USER PROFILE
void viewUserProfile()
{
    printf("\n\n");
    printf(RED "[ USER PROFILE ]\n" RESET);
    printf(RED "===================================================\n" RESET);

    printf(GREEN "Name          : %s\n" RESET, name);
    printf(GREEN "Username      : %s\n" RESET, userName);
    printf(GREEN "Email         : %s\n" RESET, email);
    printf(GREEN "Phone         : %s\n" RESET, mobileNumber);
    printf(GREEN "Address       : %s\n" RESET, address);
    printf(RED "Loyalty       : GOLD MEMBER\n" RESET);

    printf("\n");
    printf(RED "[ ACTIVITY STATS ]\n" RESET);
    printf(RED "===================================================\n" RESET);

    printf(GREEN "Total Bookings    : %d times\n" RESET, totalBookings);
    printf(GREEN "Total Seats       : %d\n" RESET, totalSeatsBooked);
    printf(GREEN "Total Spent       : Rs %.2f\n" RESET, totalMoneySpent);
    printf("\n\n");
}

// THIS is FOR userMenu
void userMenu()
{
    int userMenuOption;

    while (1)
    {
        printf(CYAN "\n< ================ User Dashboard Page ================ >\n" RESET);
        printf("1. Book Ticket\n");
        printf("2. View Profile\n");
        printf("3. Check Bus Status\n");
        printf("4. Payment\n");
        printf("5. Cancel Ticket\n");
        printf("6. Logout\n");

        printf("Select an option: ");
        scanf("%d", &userMenuOption);

        if (userMenuOption == 1)
        {
            bookBusTicket();
        }
        else if (userMenuOption == 2)
        {
            viewUserProfile();
        }
        else if (userMenuOption == 3)
        {
            checkBusStatus();
        }
        else if (userMenuOption == 4)
        {
            payment();
        }
        else if (userMenuOption == 5)
        {
            cancelBusTicket();
        }
        else if (userMenuOption == 6)
        {
            printf(GREEN "\nLogging out...\n" RESET);
            printf(GREEN "Logged out successfully!\n" RESET);
            break;
        }
        else
        {
            printf(RED "Invalid option. Please try again.\n" RESET);
        }
    }
}
