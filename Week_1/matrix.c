#include <stdio.h>
#include <string.h>

void input_matix(int m, int n, int arr[][n])
{
    printf("Enter the elements row wise :\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", *(arr + (i)) + j);
        }
    }
}

void print_matrix(int m, int n, int (*arr)[n])
{
    printf("\nMatrix\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

int main()
{
    printf("Choose a option: \n");
    printf("1 - Addition \n");
    printf("2 - Subtraction \n");
    printf("3 - Multiplication \n");
    printf("4 - Transpose \n");

    int choice, m, n, p;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        printf("Enter no. of rows and column of matrix :");
        scanf("%d%d", &m, &n);
        int arr1[m][n], arr2[m][n], res_arr[m][n];
        input_matix(m, n, arr1);
        input_matix(m, n, arr2);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res_arr[i][j] = arr1[i][j] + arr2[i][j];
            }
        }
        print_matrix(m, n, res_arr);
        break;
    }

    case 2:
    {
        printf("Enter no. of rows and column of matrix :");
        scanf("%d%d", &m, &n);
        int arr1[m][n], arr2[m][n], res_arr[m][n];
        input_matix(m, n, arr1);
        input_matix(m, n, arr2);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res_arr[i][j] = arr1[i][j] - arr2[i][j];
            }
        }
        print_matrix(m, n, res_arr);
        break;
    }

    case 3:
    {
        printf("Enter no. of rows and column of ( 1st ) matrix :");
        scanf("%d%d", &m, &n);
        printf("2nd matix will have (%d) rows \n Enter the no. columns:  ", n);
        scanf("%d", &p);
        int arr1[m][n], arr2[n][p], res_arr[m][p];
        memset(res_arr, 0, sizeof(res_arr));

        input_matix(m, n, arr1);
        input_matix(n, p, arr2);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < p; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    res_arr[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        print_matrix(m, p, res_arr);
        break;
    }

    case 4:
    {
        printf("Enter no. of rows and column of matrix :");
        scanf("%d%d", &m, &n);
        int arr1[m][n], res_arr[n][m];
        input_matix(m, n, arr1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                res_arr[i][j] = arr1[j][i];
            }
        }
        print_matrix(n, m, res_arr);
        break;
    }
    default:
        printf("\nInvalid input");
    }
}