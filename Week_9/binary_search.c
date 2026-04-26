#include <stdio.h>

int binary_search_using_loop(int arr[], int size, int item)
{
    int mid;
    int lb = 0;
    int ub = size - 1;

    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (arr[mid] == item)
        {
            return mid;
        }
        else if (arr[mid] > item)
        {
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return -1;
}

int binary_search_using_recusrion(int arr[], int lb, int ub, int item)
{
    if (lb > ub)
        return -1;

    int mid = (lb + ub) / 2;
    if (arr[mid] == item)
    {
        return mid;
    }
    else if (arr[mid] > item)
    {
        ub = mid - 1;
        return binary_search_using_recusrion(arr, lb, ub, item);
    }
    else
    {
        lb = mid + 1;
        return binary_search_using_recusrion(arr, lb, ub, item);
    }
}

int main()
{
    int n, i, choice, postion = -1, item;
    printf("How many values you want to enter :");
    scanf("%d", &n);
    int arr[n];

    printf("\nEnter values (in ascending order) :");

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
        postion = binary_search_using_loop(arr, n, item);
    }

    else if (choice == 2)
    {
        postion = binary_search_using_recusrion(arr, 0, n - 1, item);
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