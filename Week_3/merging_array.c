#include <stdio.h>

void array_print(int arr[], int n)
{
    int i;
    printf("\n\nContents of Array\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int i, j, l, n1, n2;

    printf("Enter no. of elements you want to enter for array 1: ");
    scanf("%d", &n1);
    int arr1[n1];

    printf("\nEnter the elements of arr1 in ascending order: ");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("\nEnter no. of elements you want to enter for array 2: ");
    scanf("%d", &n2);
    int arr2[n2];

    printf("\nEnter the elements of arr1 in ascending order: ");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    int arr3[n1 + n2];
    i = 0, j = 0, l = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[l] = arr1[i];
            i++;
        }
        else
        {
            arr3[l] = arr2[j];
            j++;
        }
        l++;
    }
    while (i < n1)
    {
        arr3[l] = arr1[i];
        i++, l++;
    }
    while (j < n2)
    {
        arr3[l] = arr2[j];
        j++;
        l++;
    }

    array_print(arr1, n1);
    array_print(arr2, n2);
    array_print(arr3, (n1 + n2));
}