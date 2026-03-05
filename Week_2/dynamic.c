#include <stdio.h>
#include <stdlib.h>

struct commodity_data
{
    char name[81];
    int amount;
    float price;
};
typedef struct commodity_data co_data;

int main()
{
    int n;
    printf("Enter the no. of products : ");
    scanf("%d", &n);

    co_data *p = (co_data *)malloc(n * sizeof(co_data));

    for (int i = 0; i < n; i++)
    {
        getchar();
        printf("\nEnter the name of product: ");
        fgets((p + i)->name, sizeof((p + i)->name), stdin);

        printf("Enter the price(per kg): ");
        scanf("%f", &(p + i)->price);

        printf("Enter the amount(in kg): ");
        scanf("%d", &(p + i)->amount);
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nName-  %s", (*(p + i)).name);

        printf("Price - %.2f", (*(p + i)).price);

        printf("\nAmount- %d kg", (*(p + i)).amount);
    }
}
