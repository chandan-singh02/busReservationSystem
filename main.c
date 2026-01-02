#include <stdio.h>
#include "userProfile.c"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

int main()
{
    int choice;
    for (;;)
    {
        printf(CYAN "\n<================ Welcome to YatraBus ================>\n\n" RESET);

        printf("1. SignUp\n");
        printf("2. Login\n");
        printf(RED "3. Exit\n" RESET);

        printf("Please select one option: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            signUp();
        }
        else if (choice == 2)
        {
            int userStatus = userLogin();
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
            printf(GREEN "Your journey with YatraBus ends here.\n" RESET);
            break;
        }
        else
        {
            printf(RED "You selected invalid option!\n" RESET);
        }
    }

    return 0;
}
