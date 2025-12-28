#include <stdio.h>
// int busNo = 101;
// char defaultSource[] = "Delhi";
// char defaultDestination[] = "Bihar";
// int totalSeats = 50;
// int availableSeats = 50;
// float pricePerSeat = 500.0;
// int seatsBooked = 0;
// float totalAmount = 0.0;
// float refundMoney = 0.0;
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
int totalBookings = 0;
int totalSeatsBooked = 0;
float totalMoneySpent = 0.0;

int bookBusTicket();
int cancelBusTicket();
int checkBusStatus();
// int verifyPIN();
int payment();
int generateReceipt(int index);

int findBusIndex(int enteredBusNo)
{
    for (int i = 0; i < 3; i++)
    {
        if (busNo[i] == enteredBusNo)
        {
            return i;
        }
    }
    return -1;
}

int verifyPIN(int correctPin)
{
    int pin;
    int attempts = 0;

    while (attempts < 3)
    {
        printf("Enter payment PIN             : ");
        scanf("%d", &pin);

        if (pin == correctPin)
        {
            return 1;
        }

        attempts++;
        printf("\nIncorrect PIN! Attempts left: %d\n", 2 - attempts);
    }

    printf("Account lockedd due to 3 incorrect PIN attempts\n");
    return 0;
}
int bookBusTicket()
{
    int enteredBusNo, seats;

    printf("Enter Bus Number     : ");
    scanf("%d", &enteredBusNo);

    int index = findBusIndex(enteredBusNo);

    // if (busNo[index] != enteredBusNo)

    // {
    //     printf("\ninvalid Bus Number!,Please renter\n");
    //     return 0;
    // }

    if (index == -1)
    {
        printf("\nInvalid Bus Number! Please re-enter\n");
        return 0;
    }

    printf("Enter number of seats: ");
    scanf("%d", &seats);

    if (seats <= 0)
    {
        printf("\n cant enter invalid number seats !\n");
        return 0;
    }

    if (availableSeats[index] >= seats)
    {
        availableSeats[index] -= seats;
        seatsBooked[index] += seats;
        totalAmount[index] += seats * pricePerSeat[index];

        printf("\nBooking successfull! You Booked %d seats\n", seats);
        printf("Proceed to payment.\n");
        return 1;
    }
    else
    {
        printf("\nNot enough seats available!\n");
        return 0;
    }
}

// this is cancel ticket
int cancelBusTicket()
{
    int enteredBusNo, seats;
    printf("Enter Bus Number               : ");
    scanf("%d", &enteredBusNo);

    int index = findBusIndex(enteredBusNo);
    if (index == -1)
    {
        printf("Invalid bus number\n");
        return 0;
    }

    printf("Enter number of seats to cancel: ");
    scanf("%d", &seats);

    // if (enteredBusNo != busNo)
    // {
    //     printf("Invalid bus number,please enter valid one");
    //     return 0;
    // }

    if (seats <= 0)
    {
        printf("\nInvalid number! Please enter how many seats u want cancel\n");
        return 0;
    }

    if (seatsBooked[index] == 0)
    {
        printf("\n0 seats Booked ! Please book a ticket first\n");
        return 0;
    }
    if (seats > seatsBooked[index])
    {
        printf("\nYou cannot cancel %d ,because u booked only %d seats\n ", seats, seatsBooked[index]);
        return 0;
    }
    // refundMoney = seats * pricePerSeat[index];
    // refundMoney -= totalAmount;
    // availableSeats[index] += seats;
    // seatsBooked -= seats;
    refundMoney[index] = seats * pricePerSeat[index];
    totalAmount[index] -= refundMoney[index];
    availableSeats[index] += seats;
    seatsBooked[index] -= seats;

    printf("\n%d seats cancelled successfully  \n\n", seats);
    printf("Remaining seats booked             : %d\n", seatsBooked[index]);
    printf("Remaining amount to pay            : %.2f\n", totalAmount[index]);

    return 1;
}

// this is bus details
int checkBusStatus()
{
    int enteredbusNo;
    printf("--------------- [ BUS DETAILS PAGE ] ---------------\n");
    printf("Please enter your bus number: ");
    scanf("%d", &enteredbusNo);

    int index = findBusIndex(enteredbusNo);

    if (index == -1)
    {
        printf("Invalid bus number\n");
        return 0;
    }
    printf("\n");
    printf("[ BUS DETAILS ]\n");
    printf("===================================================\n");
    printf("Bus Number        : %d\n", busNo[index]);
    printf("Route             : %s --> %s\n", source[index], destination[index]);
    printf("Total Seats       : %d\n", totalSeats[index]);
    printf("Available Seats   : %d\n", availableSeats[index]);
    printf("Seats Booked      : %d\n", seatsBooked[index]);
    printf("Price per Seat    : %.2f\n", pricePerSeat[index]);
    printf("Total Amount      : %.2f\n", totalAmount[index]);
    // printf("Refund Amount     : %.2f\n", refundMoney);

    return 1;
}

// this is payment
int payment()
{
    int pin, enteredBusNo;
    int correctPin = 123456;

    printf("--------------- [ PAYMENT GATEWAY PAGE ] ---------------\n");

    printf("Enter Bus Number for payment: ");
    scanf("%d", &enteredBusNo);

    int index = findBusIndex(enteredBusNo);
    if (index == -1)
    {
        printf("Invalid bus number\n");
        return 0;
    }

    if (seatsBooked[index] <= 0)
    {
        printf("\n%d  seats Booked till now\n", seatsBooked[index]);
        return 0;
    }

    printf("\nTotal Amount to Pay           : %.2f\n", totalAmount[index]);
    if (!verifyPIN(correctPin))
    {
        return 0;
    }

    // if (pin != correctPin)
    // {
    //     printf("\nPayment Failed , Incorrect PIN ,Please Try again!\n");
    //     return 0;
    // }

    if (bankBalance <= 0)
    {
        printf("\nInsufficient balance! Your bank balance is %.2f\n", bankBalance);
        return 0;
    }

    if (bankBalance < totalAmount[index])
    {
        printf("\nInsufficient balance! Required %.2f but available %.2f\n",
               totalAmount[index], bankBalance);
        return 0;
    }
    printf("\nPayment Processing...\n");
    printf("Payment Successful   \n");

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
    printf("\n");
    printf("[ BUS TICKET RECEIPT ]\n");
    printf("===================================================\n");
    printf("Bus Number        : %d\n", busNo[index]);
    printf("Route             : %s --> %s\n", source[index], destination[index]);
    printf("Seats Booked      : %d\n", seatsBooked[index]);
    printf("Price per Seat    : %.2f\n", pricePerSeat[index]);
    printf("--------------------------------------------------------\n");
    printf("Total Amount Paid : %.2f\n", totalAmount[index]);
    printf("Payment Status    : SUCCESSFUL\n");
    return 1;
}
