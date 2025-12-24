#include <stdio.h>

struct Bus
{
    int busNo;
    char source[20];
    char destination[20];
    int totalSeats;
    int availableSeats;
    float price;
};

struct Bus buses[7] = {
    {101, "Delhi", "Bihar", 50, 45, 500.00},
    {102, "Delhi", "Uttrakhand", 45, 40, 450.00},
    {103, "Mumbai", "Pune", 40, 35, 300.00},
    {104, "Chennai", "Bangalore", 50, 48, 550.00},
    {105, "Kolkata", "Patna", 55, 50, 600.00},
    {106, "Delhi", "Pune", 40, 35, 1000.00},
    {107, "Kolkata", "Bangalore", 50, 48, 550.00},
};
