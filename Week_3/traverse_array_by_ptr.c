#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    int *ptr = arr;

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    printf("\nContents of array\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }
}