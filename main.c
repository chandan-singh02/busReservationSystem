#include <stdio.h>
#include "userProfile.c"

int main()
{
    int choice;

    for (;;)
    {
        printf("\n<================ Welcome to YatraBus ================>\n\n");
        printf("1. SignUp\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Please select one option: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            signUp();
        }
        else if (choice == 2)
        {
            int userStatus = userLogin();
            // printf("%d", userStatus);
            if (userStatus == 1)
            {
                userMenu();
            }
            else
            {
                continue;
            }
        }
        else if (choice == 3)
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
