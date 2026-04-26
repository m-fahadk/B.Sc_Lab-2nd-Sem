#include <stdio.h>

void insertion_sort(int arr[], int size)
{
	int arr_ls, arr_fu, temp, pass;

	for (pass = 1; pass < size; pass++)
	{
		arr_fu = pass;
		arr_ls = pass - 1;
		temp = arr[arr_fu];

		while (arr_ls >= 0 && arr[arr_fu] < arr[arr_ls])
		{
			arr[arr_ls + 1] = arr[arr_ls];
			arr_ls--;
		}
		arr[arr_ls + 1] = temp;
	}
}

void selection_sort(int arr[], int size)
{
	int temp, pass, i, local_min;
	for (pass = 0; pass < size; pass++)
	{
		local_min = pass;
		for (i = pass; i < size; i++)
		{
			if (arr[i] < arr[local_min])
			{
				local_min = i;
			}
		}
		if (local_min != pass)
		{
			temp = arr[pass];
			arr[pass] = arr[local_min];
			arr[local_min] = temp;
		}
	}
}

void int_traversal(int arr[], int size)
{
	int i;
	printf("\nSorted array- ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

void char_traversal(char arr[], int size)
{
	int i;
	printf("\nSorted array- ");
	for (i = 0; i < size; i++)
	{
		printf("%c ", arr[i]);
	}
}

void bubble_sort_for_char(char arr[], int size)
{
	int pass, i, temp, changed;
	for (pass = 1; pass < size; pass++)
	{
		changed = 0;
		for (i = 0; i <= size - 1 - pass; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				changed = 1;
			}
		}
		if (!changed)
			break;
	}
}
int partition(char arr[], int lb, int ub);
void quicksort(char arr[], int lb, int ub)
{
	int j;
	if (lb < ub)
	{
		j = partition(arr, lb, ub);
		quicksort(arr, lb, j - 1);
		quicksort(arr, j + 1, ub);
	}
}

int partition(char arr[], int lb, int ub)
{
	int i, j, key, temp;
	i = lb + 1;
	j = ub;
	key = arr[lb];

	while (i <= j)
	{
		while (arr[i] < key && i <= j)
			i++;
		while (arr[j] > key)
			j--;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
		else
			break;
	}
	temp = arr[lb];
	arr[lb] = arr[j];
	arr[j] = temp;
	return j;
}

int main()
{
	int choice, size, i;
	do
	{
		printf("\nMENU\n");
		printf("Choose an option\n");
		printf("1. Insertion sort for integers\n2. Bubble sort for characters\n3. Selection sort for integers\n4. Quick sort for characters\n5. Exit\n> ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			printf("Enter the no. of elements you want to enter :");
			scanf("%d", &size);
			int arr[size];
			printf("\nEnter the elements : ");

			for (i = 0; i < size; i++)
			{
				scanf("%d", &arr[i]);
			}

			insertion_sort(arr, size);
			int_traversal(arr, size);
			break;
		}

		case 2:
		{
			printf("Enter the no. of elements you want to enter :");
			scanf("%d", &size);
			char arr[size];

			printf("\nEnter the elements : ");
			for (i = 0; i < size; i++)
			{
				scanf(" %c", &arr[i]);
			}
			bubble_sort_for_char(arr, size);
			char_traversal(arr, size);
			break;
		}

		case 3:
		{
			printf("Enter the no. of elements you want to enter :");
			scanf("%d", &size);
			int arr[size];
			printf("\nEnter the elements : ");

			for (i = 0; i < size; i++)
			{
				scanf("%d", &arr[i]);
			}

			selection_sort(arr, size);
			int_traversal(arr, size);
			break;
		}
		case 4:
		{
			printf("Enter the no. of elements you want to enter :");
			scanf("%d", &size);
			char arr[size];

			printf("\nEnter the elements : ");
			for (i = 0; i < size; i++)
			{
				scanf(" %c", &arr[i]);
			}
			quicksort(arr, 0, size);
			char_traversal(arr, size);
			break;
		}
		}
	} while (choice != 5);
}