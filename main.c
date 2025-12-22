#include <stdio.h>
#include "userProfile.c"

int main()
{
    int choice;

    for (;;)
    {
        printf("\n<----------Welcome to YatraBus---------->\n\n");
        printf("1. Login\n");
        printf("2. Exit\n");
        printf("Select one option: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int userStatus = userLogin();

            if (userStatus == 1)
            {
                userMenu();
            }
            else
            {
                printf("Fill the form again!\n");
            }
        }
        else if (choice == 2)
        {
            printf("Your journey with YatraBus ends here.\n");
            break;
        }
        else
        {
            printf("You selected invalid option!\n");
        }
    }

    return 0;
}
