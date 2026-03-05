#include <stdio.h>
#include <string.h>

void strrev(char str[81])
{
    char strcopy[81];
    strcpy(strcopy, str);

    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        str[i] = strcopy[len - i - 1];
    }
}

int main()
{
    char str1[81], str2[200];
    int choice;
    printf("Enter a string(max length 80) : ");
    fgets(str1, 81, stdin);
    char *postion = strchr(str1, '\n');

    if (postion != NULL)
    {
        *postion = '\0';
    }

    printf("Choose a option\n1- Addition\n2- Copying\n3- Reverse\n4- Length of string\n");
    scanf("%d", &choice);

    if (choice == 1)
    {

        getchar();
        printf("\nEnter 2nd string(max length 80) : ");
        fgets(str2, 200, stdin);
        strcat(str1, str2);
        printf("\nResult = %s", str1);
    }

    else if (choice == 2)
    {
        strcpy(str2, str1);
        printf("\nResult = %s", str2);
    }

    else if (choice == 3)
    {
        strrev(str1);
        printf("\nResult = %s", str1);
    }

    else if (choice == 4)
    {
        int l = strlen(str1);
        printf("Length of string = %ld", strlen(str1));
    }

    else
        printf("Invalid choice");
}

}
