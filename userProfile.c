#include <stdio.h>
#include <string.h>
#include "busBookingProfile.c"

int userLogin();
void userMenu();
int verifyOTP();
char name[20];
char email[30];
char userName[20];
char password[20];
char gender[8];
char mobileNumber[10];
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
            printf("\nSignup successful! Please login.\n");
            return 1;
        }

        attempts++;

        if (attempts < 3)
        {
            printf("Incorrect OTP! Attempts left: %d\n", 3 - attempts);
        }
    }

    printf("OTP verification failed. Please signup again.\n");
    return 0;
}

// this for signup
int signUp()
{

    printf("\n");
    printf("--------------- [ USER SIGNUP PAGE ] ---------------\n");
    printf("please enter your name     : ");
    scanf(" %[^\n]", &name);
    printf("please enter your username : ");
    scanf("%s", &userName);
    printf("please enter your email    : ");
    scanf("%s", &email);
    printf("please enter your mobileNo : ");
    scanf("%s", &mobileNumber);
    printf("please enter your gender   : ");
    scanf("%s", &gender);
    printf("please enter your password : ");
    scanf("%s", &password);

    // printf("please enter your name     :\n");
    // scanf("%s", &enteredOTP);

    if (strlen(userName) < 3)
    {
        printf("\nUsername must be at least 3 characters long.\n");
        isSignUp = 0;
        return 0;
    }

    if (strlen(password) < 6)
    {
        printf("\nPassword must be at least 6 characters long.\n");
        isSignUp = 0;
        return 0;
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
        printf("\nNo user found database. Please signup first!\n");
        return 0;
    }

    printf("\n");
    printf("--------------- [ USER LOGIN PAGE ] ---------------\n");

    printf("Please enter your username: ");
    scanf("%s", &loginUsername);

    printf("Please enter your password: ");
    scanf("%s", &loginPassword);

    if (strcmp(loginUsername, userName) == 0 &&
        strcmp(loginPassword, password) == 0)
    {
        printf("\nLogin successful. Welcome, %s\n", name);
        return 1;
    }
    else
    {
        printf("\nInvalid username or password!\n");
        return 0;
    }
}
void viewUserProfile()
{
    printf("\n\n");
    printf("[ USER PROFILE ]\n");
    printf("===================================================\n");

    printf("Name         : %s\n", name);
    printf("Username     : %s\n", userName);
    printf("Phone        : %s\n", mobileNumber);
    printf("Gender       : %s\n", gender);
    printf("Email        : %s\n", email);
    printf("Loyalty      : GOLD MEMBER\n");
    printf("\n");

    printf("\n");

    printf("[ ACTIVITY STATS ]\n");
    printf("===================================================\n");

    printf("Total Bookings    : %d times\n", totalBookings);
    printf("Total Seats       : %d\n", totalSeatsBooked);
    printf("Total Spent       : Rs %.2f\n", totalMoneySpent);
    printf("\n\n");
}

// THIS is userMenu
void userMenu()
{
    int userMenuOption;

    while (1)
    {
        printf("\n< ================ User Dashboard Page ================ >\n");
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
            printf("\nBook Ticket selected\n");
            bookBusTicket();
            // Auto-redirect to payment after successful booking
            // if (bookBusTicket())
            // {
            //     printf("\nRedirecting to Payment...\n");
            //     payment();
            // }
        }
        else if (userMenuOption == 2)
        {
            viewUserProfile();
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
            printf("\nCancel Ticket selected\n");
            cancelBusTicket();
        }
        else if (userMenuOption == 6)
        {
            printf("\nLogging out...\n");
            printf("Logged out successfully!\n");
            break;
        }
        else
        {
            printf("Invalid option. Please try again.\n");
        }
    }
}
