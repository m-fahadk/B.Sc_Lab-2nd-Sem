#include <stdio.h>

int main()
{
    char str1[81], str2[81];

    printf("Enter a string(max 80 character)\n");
    fgets(str1, 81, stdin);
    int i = 0;
    int j = 0;
    char letter = str1[0];

    while (letter != '\0')
    {
        if (!(letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U' || letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u'))
        {
            str2[j] = str1[i];
            i++;
            j++;
        }
        else
            i++;
        letter = str1[i];
    }
    str2[j] = '\0';

    printf("New string - ");
    printf("%s", str2);
}