#include <stdio.h>

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    int *ptr = arr;

    printf("Enter elements of the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int index;
    printf("Enter index to access: ");
    scanf("%d", &index);

    if (index >= 0 && index < n)
    {
        printf("Element at index %d is: %d\n", index, *(ptr + index));
    }
    else
    {
        printf("Invalid index!\n");
    }

    return 0;
}
