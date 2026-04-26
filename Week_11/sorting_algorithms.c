#include <stdio.h>

void printArray(int arr[], int n)
{
    printf("[ ");
    for (int i = 0; i < n; i++)
        printf("%d%s", arr[i], (i < n - 1) ? ", " : " ");
    printf("]\n");
}

void countingSort(int arr[], int n)
{
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;

    int count[range];
    int output[n];

    for (int i = 0; i < range; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            i++;
        }
        else
        {
            int value = arr[j];
            int k = j;
            while (k > i)
            {
                arr[k] = arr[k - 1];
                k--;
            }
            arr[i] = value;

            i++;
            mid++;
            j++;
        }
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main(void)
{
    printf("╔══════════════════════════════════════╗\n");
    printf("║        SORTING ALGORITHMS — C        ║\n");
    printf("╚══════════════════════════════════════╝\n\n");

    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];
    int workArr[n];

    printf("Enter %d integer(s): ", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }
    }

    printf("\nOriginal array : ");
    printArray(arr, n);

    int choice;
    printf("\n┌─────────────────────────────────────┐\n");
    printf("│  Choose a Sorting Algorithm:         │\n");
    printf("│  1. Counting Sort                    │\n");
    printf("│  2. Merge Sort                       │\n");
    printf("│  3. Heap Sort                        │\n");
    printf("└─────────────────────────────────────┘\n");
    printf("Enter your choice (1-3): ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid choice!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        workArr[i] = arr[i];

    switch (choice)
    {
    case 1:
        countingSort(workArr, n);
        break;

    case 2:
        mergeSort(workArr, 0, n - 1);
        break;

    case 3:
        heapSort(workArr, n);
        break;

    default:
        printf("Invalid choice! Please select 1, 2, or 3.\n");
        return 1;
    }

    printf("\nSorted array  : ");
    printArray(workArr, n);

    return 0;
}
