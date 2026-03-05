#include <stdio.h>
#include <string.h>

int main()
{
    char str[81];
    int vowel_count = 0, consonant_count = 0, digit_count = 0, white_space_count = 0, i = 0, others = 0;

    printf("Enter a string(max len 80)\n");
    fgets(str, 81, stdin);

    str[strcspn(str, "\n")] = '\0';
    while (str[i] != '\0')
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
                vowel_count++;
            else
                consonant_count++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
            digit_count++;

        else if (str[i] == ' ' || str[i] == '\t')
            white_space_count++;

        else
            others++;

        i++;
    }
    printf("\nVowels = %d\n", vowel_count);
    printf("Consonats = %d\n", consonant_count);
    printf("Digits = %d\n", digit_count);
    printf("White Spaces = %d\n", white_space_count);
    printf("Others = %d", others);
}