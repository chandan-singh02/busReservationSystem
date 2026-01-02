#include <stdio.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

int busNo[3] = {101, 102, 103};
char source[3][20] = {"Delhi", "Mumbai", "Delhi"};
char destination[3][20] = {"Bihar", "Banglore", "Uttrakhand"};
int totalSeats[3] = {50, 40, 45};
int availableSeats[3] = {50, 40, 45};
float pricePerSeat[3] = {1500, 2000, 1000};

int seatsBooked[3] = {0, 0, 0};
float totalAmount[3] = {0.0, 0.0, 0.0};
float refundMoney[3] = {0.0, 0.0, 0.0};

float bankBalance = 16050.00;

// user stats
int totalBookings = 0;
int totalSeatsBooked = 0;
float totalMoneySpent = 0.0;

int bookBusTicket();
int cancelBusTicket();
int checkBusStatus();
int payment();
int generateReceipt(int index);

int findBusIndex(int userBusNo)
{
    for (int i = 0; i < 3; i++)
    {
        if (busNo[i] == userBusNo)
            return i;
    }
    return -1;
}

int findBusNumber()
{
    int userBusNo;

    printf("\nEnter Bus Number      : ");
    scanf("%d", &userBusNo);

    int index = findBusIndex(userBusNo);
    return index;
}

int getValidSeats()
{
    int seats;

    printf("Enter number of seats  : ");
    scanf("%d", &seats);

    if (seats <= 0)
    {
        printf(RED "\nCannot enter invalid seat count!\n" RESET);
        return 0;
    }
    return seats;
}

int verifyPIN(int correctPin)
{
    int pin;
    int attempts = 0;

    while (attempts < 3)
    {
        printf("Enter payment PIN   : ");
        scanf("%d", &pin);

        if (pin == correctPin)
            return 1;

        attempts++;
        printf(RED "\nIncorrect PIN! Attempts left: %d\n" RESET, 2 - attempts);
    }

    printf(RED "Account locked due to 3 incorrect PIN attempts\n" RESET);
    return 0;
}

// book bus ticket
int bookBusTicket()
{
    int index = findBusNumber();
    if (index == -1)
    {
        printf(RED "\nInvalid Bus Number!\n" RESET);
        return 0;
    }
    int seats = getValidSeats();

    if (availableSeats[index] >= seats)
    {
        availableSeats[index] -= seats;
        seatsBooked[index] += seats;
        totalAmount[index] += seats * pricePerSeat[index];

        printf(GREEN "\nBooking successful! You booked %d seats\n" RESET, seats);
        printf("Proceed to payment.\n");
        return 1;
    }
    else
    {
        printf(RED "\nNot enough seats available!\n" RESET);
        return 0;
    }
}

// cancel ticket
int cancelBusTicket()
{
    int index = findBusNumber();
    if (index == -1)
    {
        printf(RED "\nInvalid Bus Number!\n" RESET);
        return 0;
    }

    int seats = getValidSeats();

    if (seatsBooked[index] == 0)
    {
        printf(RED "\nNo seats booked yet!\n" RESET);
        return 0;
    }

    if (seats > seatsBooked[index])
    {
        printf(RED "\nYou cannot cancel %d seats, only %d booked\n" RESET,
               seats, seatsBooked[index]);
        return 0;
    }

    refundMoney[index] = seats * pricePerSeat[index];
    totalAmount[index] -= refundMoney[index];
    availableSeats[index] += seats;
    seatsBooked[index] -= seats;

    printf(GREEN "\n%d seats cancelled successfully\n" RESET, seats);
    printf("Remaining seats booked : %d\n", seatsBooked[index]);
    printf("Remaining amount       : %.2f\n", totalAmount[index]);

    return 1;
}

// bus details
int checkBusStatus()
{
    printf(CYAN "\nBUS DETAILS PAGE\n" RESET);
    printf(CYAN "--------------------------------\n" RESET);

    int index = findBusNumber();
    if (index == -1)
    {
        printf(RED "\nInvalid Bus Number!\n" RESET);
        return 0;
    }

    printf(CYAN "[ BUS DETAILS ]\n" RESET);
    printf(CYAN "===================================================\n" RESET);
    printf("Bus Number        : %d\n", busNo[index]);
    printf("Route             : %s --> %s\n", source[index], destination[index]);
    printf("Total Seats       : %d\n", totalSeats[index]);
    printf("Available Seats   : %d\n", availableSeats[index]);
    printf("Seats Booked      : %d\n", seatsBooked[index]);
    printf("Price per Seat    : %.2f\n", pricePerSeat[index]);
    printf("Total Amount      : %.2f\n", totalAmount[index]);

    return 1;
}

// payment
int payment()
{
    int correctPin = 123456;

    printf(CYAN "\nPAYMENT GATEWAY PAGE\n" RESET);
    printf(CYAN "--------------------------------\n" RESET);

    int index = findBusNumber();
    if (index == -1)
    {
        printf(RED "\nInvalid Bus Number!\n" RESET);
        return 0;
    }

    if (seatsBooked[index] <= 0)
    {
        printf(RED "\nNo seats booked for payment\n" RESET);
        return 0;
    }

    printf("\nTotal Amount to Pay : %.2f\n", totalAmount[index]);

    if (!verifyPIN(correctPin))
        return 0;

    if (bankBalance < totalAmount[index])
    {
        printf(RED "\nInsufficient balance!\n" RESET);
        return 0;
    }
    printf(GREEN "\nPayment Processing...\n" RESET);
    printf(GREEN "\nPayment Successful\n" RESET);

    totalSeatsBooked += seatsBooked[index];
    totalMoneySpent += totalAmount[index];
    bankBalance -= totalAmount[index];

    printf("Remaining Bank Balance : %.2f\n", bankBalance);

    generateReceipt(index);

    seatsBooked[index] = 0;
    totalAmount[index] = 0.0;
    refundMoney[index] = 0.0;
    totalBookings++;

    return 1;
}

int generateReceipt(int index)
{
    printf(RED "\n[ BUS TICKET RECEIPT ]\n" RESET);
    printf(RED "===================================================\n" RESET);

    printf(GREEN "Bus Number        : %d\n" RESET, busNo[index]);
    printf(GREEN "Route             : %s --> %s\n" RESET, source[index], destination[index]);
    printf(GREEN "Seats Booked      : %d\n" RESET, seatsBooked[index]);
    printf(GREEN "Price per Seat    : %.2f\n" RESET, pricePerSeat[index]);
    printf(GREEN "Total Amount Paid : %.2f\n" RESET, totalAmount[index]);
    printf(GREEN "Payment Status    : SUCCESSFUL\n" RESET);

    return 1;
}
