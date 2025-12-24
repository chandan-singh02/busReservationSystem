#include <stdio.h>
#include "busData.c"

int bookBusTicket();
int cancelBusTicket();
int checkBusStatus();
int payment();
int generateReceipt();

extern struct Bus buses[7];

float totalAmount = 0.0;
int busNo = 0;
int seatsBooked = 0;
// char source[30] = "";
// char destination[30] = "";
float pricePerSeat = 0.0;

int bookBusTicket()
{
    int enteredbusNo, seats;

    printf("Please enter your bus number: ");
    scanf("%d", &enteredbusNo);

    printf("Please enter number of seats: ");
    scanf("%d", &seats);

    for (int i = 0; i < 7; i++)
    {
        if (buses[i].busNo == enteredbusNo)
        {
            if (buses[i].availableSeats >= seats)
            {
                buses[i].availableSeats -= seats;
                totalAmount = seats * buses[i].price;
                busNo = buses[i].busNo;
                seatsBooked = seats;
                totalAmount = seats * buses[i].price;
                pricePerSeat = buses[i].price;

                // source= buses[i].source;
                // destination= buses[i].destination;

                printf("\nSuccessfully added to the cart ,%d seats added on Bus Number %d\n",
                       seats, enteredbusNo);
                printf("Proceed to payment from menu.\n");
                // payment(busNo, i);
            }
            else
            {
                printf("\nNot enough seats available\n");
                return 0;
            }
            return 0;
        }
    }

    printf("\nBus not found! Please enter a valid bus number\n");
    return 1;
}

int cancelBusTicket()
{
    int busNo, seats;

    printf("Please enter your bus number          : ");
    scanf("%d", &busNo);

    printf("Please enter number of seats to cancel: ");
    scanf("%d", &seats);

    for (int i = 0; i < 7; i++)
    {
        if (buses[i].busNo == busNo)
        {
            if (buses[i].availableSeats >= seats)
            {
                buses[i].availableSeats += seats;
                printf("\nCancellation successfull! %d seats canceled on Bus Number %d\n",
                       seats, busNo);
            }
            else
            {
                printf("\nNot enough seats available\n");
                return 0;
            }
        }
    }

    // printf("\nBus not found! Please enter a valid bus number\n");
    return 1;
}

int checkBusStatus()
{
    int busNo, found;

    printf("Please enter your bus number: ");
    scanf("%d", &busNo);

    for (int i = 0; i < 7; i++)
    {
        if (busNo == buses[i].busNo)
        {
            printf("========= Bus Details =========\n");
            printf("Bus Number       : %d\n", buses[i].busNo);
            printf("Source           : %s\n", buses[i].source);
            printf("Destination      : %s\n", buses[i].destination);
            printf("Total Seats      : %d\n", buses[i].totalSeats);
            printf("Available Seats  : %d\n", buses[i].availableSeats);
            printf("price            : %.2f\n", buses[i].price);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\n Bus number %d not found.\n", busNo);
        return 0;
    }

    return 1;
}

int payment()
{
    int pin;
    int correctPin = 123456;

    printf("<--------------------  Payment Gateway Page -------------------- ->\n");
    printf("Total Amount to Pay : %.2f\n", totalAmount);
    printf("Enter payment PIN   : ");
    scanf("%d", &pin);

    if (pin == correctPin)
    {
        printf("\nPayment Successful\n");
        generateReceipt();
    }
    else
    {
        printf("\nPayment Failed , Incorrect PIN ,Please Try again!\n");
        return 0;
    }
    return 1;
}

int generateReceipt()
{
    printf("\n<========= PAYMENT RECEIPT ========= >\n");
    printf("Bus Number      : %d\n", busNo);
    // printf("Route        : %s %s\n", source, destination);
    printf("Seats Booked    : %d\n", seatsBooked);
    printf("price per Seat  : %.2f\n", pricePerSeat);
    printf("Total Paid      : %.2f\n", totalAmount);
    printf("Payment Status  : SUCCESS\n");

    return 1;
}
