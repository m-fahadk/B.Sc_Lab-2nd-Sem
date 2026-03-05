#include <stdio.h>

int main()
{
    int arr1[5] = {0};
    int arr2[5] = {12};
    int arr3[5];

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");
}