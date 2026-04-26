#include <stdio.h>

int linear_search_with_loop(int arr[], int size, int item)
{
    int i = 0;
    while (i < size)
    {
        if (arr[i] == item)
            return i;
        i++;
    }

    return -1;
}

int linear_search_with_recursion(int arr[], int size, int item, int i)
{
    if (i >= size)
    {
        return -1;
    }
    if (arr[i] == item)
    {
        return i;
    }
    return linear_search_with_recursion(arr, size, item, i + 1);
}

int main()
{
    int n, i, choice, postion, item;
    printf("How many values you want to enter :");
    scanf("%d", &n);
    int arr[n];

    printf("\nEnter values :");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the digit you want to search :");
    scanf("%d", &item);

    printf("\nChoose and option\n");
    printf("1.Search by loop\n2.Search by recursion\n> ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        postion = linear_search_with_loop(arr, n, item);
    }

    else if (choice == 2)
    {
        postion = linear_search_with_recursion(arr, n, item, 0);
    }
    else
    {
        printf("\nInvalid input");
    }

    if (postion == -1)
    {
        printf("\nItem not found");
    }
    else
    {
        printf("Postion = %d", postion);
    }
}