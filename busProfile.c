#include <stdio.h>
#include "busData.c"
void bookBusTicket();

extern struct Bus buses[7];
void bookBusTicket()
{
    int busNo, seats;

    printf("Please enter your bus number: ");
    scanf("%d", &busNo);

    printf("Please enter number of seats: ");
    scanf("%d", &seats);

    for (int i = 0; i < 7; i++)
    {
        if (buses[i].busNo == busNo)
        {
            if (buses[i].availableSeats >= seats)
            {
                buses[i].availableSeats -= seats;
                printf("\nBooking successful! %d seats booked on Bus Number %d\n",
                       seats, busNo);
            }
            else
            {
                printf("\nNot enough seats available\n");
            }
            return;
        }
    }

    printf("\nBus not found! Please enter a valid bus number\n");
}
