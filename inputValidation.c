#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int lengthCalculate(char str[])
{
    return strlen(str);
}

int isValidStart(char str[])
{
    char start = str[0];

    if ((start >= 'A' && start <= 'Z') ||
        (start >= 'a' && start <= 'z'))
        return 1;

    printf(RED "\nMust start with an alphabet.\n" RESET);
    return 0;
}

int isValidEnd(char str[])
{
    int len = lengthCalculate(str);
    char end = str[len - 1];

    if ((end >= 'A' && end <= 'Z') ||
        (end >= 'a' && end <= 'z'))
        return 1;

    printf(RED "\nMust end with an alphabet.\n" RESET);
    return 0;
}

int isValidName(char name[])
{
    int len = lengthCalculate(name);

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(name[i]))
        {
            printf(RED "Name must contain only alphabets.\n" RESET);
            return 0;
        }
    }
    return 1;
}

int isValidPassword(char password[])
{
    int hasChar = 0, hasDigit = 0;
    int len = lengthCalculate(password);

    if (len < 3)
    {
        printf(RED "password must be more than 3 characters\n" RESET);
        return 0;
    }
    for (int i = 0; i < len; i++)
    {
        if (isalpha(password[i]))
            hasChar = 1;
        if (isdigit(password[i]))
            hasDigit = 1;
    }

    if (hasChar && hasDigit)
    {

        return 1;
    }

    printf(RED "Password must contain at least 1 letter and 1 digit.\n" RESET);
    return 0;
}

int isValidMobile(char mobile[])
{
    int len = lengthCalculate(mobile);

    if (len != 10)
    {
        printf(RED "Mobile number must be exactly 10 digits.\n" RESET);
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        if (!isdigit(mobile[i]))
        {
            printf(RED "Only digits allowed in mobile number.\n" RESET);
            return 0;
        }
    }

    int sameCount = 1;
    for (int i = 1; i < len; i++)
    {
        if (mobile[i] == mobile[i - 1])
        {
            sameCount++;
            if (sameCount >= 5)
            {
                printf(RED "Same digit cannot repeat 5 times.\n" RESET);
                return 0;
            }
        }
        else
            sameCount = 1;
    }
    return 1;
}

int isValidUsername(char username[])
{
    int len = lengthCalculate(username);
    int digitCount = 0;
    if (len < 3)
    {
        printf(RED "username must be more than 3 characters\n" RESET);
        return 0;
    }
    if (!isValidStart(username))
        return 0;

    for (int i = 0; i < len; i++)
    {
        if (isdigit(username[i]))
            digitCount++;

        if (digitCount > 4)
        {
            printf(RED "Username cannot contain more than 4 digits.\n" RESET);
            return 0;
        }

        if (!isalnum(username[i]))
        {
            printf(RED "Username can contain only letters and digits.\n" RESET);
            return 0;
        }
    }
    return 1;
}

int isValidEmail(char email[])
{
    int len = lengthCalculate(email);
    int Count = 0;

    if (len < 10)
    {
        printf(RED "Email must be at least 10 characters.\n" RESET);
        return 0;
    }

    if (!isValidStart(email))
        return 0;

    for (int i = 0; i < len; i++)
    {
        char ch = email[i];

        if (ch == ' ' || ch == '_' || ch == '-')
        {
            printf(RED "Spaces, underscore and hyphen not allowed.\n" RESET);
            return 0;
        }

        if (ch == '@')
            Count++;
    }

    if (Count != 1)
    {
        printf(RED "Email must contain exactly one @.\n" RESET);
        return 0;
    }
    return 1;
}
