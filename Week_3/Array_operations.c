#include <stdio.h>

void insertion(int a[], int n, int *m, int item, int k)
{
	int i;
	if (*m == (n - 1))
		printf("Array full (insertion not possible)\n");

	else if (k < 0 || k > (*m + 1))
		printf("Invalid value of index for insertion\n");

	else
	{
		for (i = *m; i >= k; i--)
			a[i + 1] = a[i];

		a[k] = item;
		*m = *m + 1;
	}
}

void deletion(int a[], int *m, int k)
{
	int i;
	if (*m == -1)
		printf("Array empty (deletion not possible)\n");

	else if (k < 0 || k > (*m))
		printf("Invalid value of array index for deletion\n");

	else
	{
		for (i = k + 1; i <= (*m); i++)
			a[i - 1] = a[i];

		*m = *m - 1;
	}
}

void traversal(int a[], int n, int m)
{
	int i = 0;
	if (m == -1)
	{
		printf("\nArray empty\n");
		return;
	}

	printf("\nContents of Array:\n");
	for (i = 0; i <= m; i++)
		printf("%d ", a[i]);

	printf("\n");
}

int main()
{
	const int n = 25;
	int choice, item, mid, index;
	int arr[25] = {5, 7, 8, 9, 2, 5, 3, 6, 7, 2, 6, 2};
	int m = 11;

	do
	{
		printf("\nMENU (Array Operations):");
		printf("\n 1.Insertion at the specified index");
		printf("\n 2.Deletion at the specified index");
		printf("\n 3.Display the contents of array");
		printf("\n 0.Exit");
		printf("\nChoice :");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter an int value to be inserted: ");
			scanf("%d", &item);
			printf("Enter index no. ( 0 to %d): ", m + 1);
			scanf("%d", &index);
			insertion(arr, n, &m, item, index);
			break;

		case 2:
			printf("Enter index no.: ( <= %d): ", m);
			scanf("%d", &index);
			deletion(arr, &m, index);
			break;

		case 3:
			traversal(arr, n, m);
			break;
		}
	} while (choice != 0);
}
