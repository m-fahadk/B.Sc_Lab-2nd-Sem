#include <stdio.h>
#include <string.h>

int main()
{
    char str1[81], str2[81], given_word[21], word2[21];
    str2[0] = '\0';

    printf("Enter a string(max 80 character)\n");
    fgets(str1, 81, stdin);

    printf("Enter a word to remove(max 20 character)\n");
    fgets(given_word, 21, stdin);
    given_word[strcspn(given_word, "\n")] = '\0';
    int i = 0;
    int j = 0;

    while (str1[i] != '\0' && str1[i] != '\n')
    {
        word2[j] = str1[i];
        i++, j++;

        if (str1[i] == ' ')
        {
            word2[j] = '\0';
            if (!(strcmp(given_word, word2) == 0))
            {
                strcat(str2, word2);
                strcat(str2, " ");
            }
            j = 0;
            i++;
        }
    }
    word2[j] = '\0';
    if (!(strcmp(given_word, word2) == 0))
    {
        strcat(str2, word2);
    }
    printf("New sentence- %s", str2);
}