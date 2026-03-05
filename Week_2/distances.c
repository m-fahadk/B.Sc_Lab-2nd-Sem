#include <stdio.h>

struct distances
{
    int feet;
    int inches;
};

int main()
{
    struct distances d1, d2, d3;

    printf("Enter the distance in (feet and inches) : ");
    scanf("%d%d", &d1.feet, &d1.inches);

    printf("Enter the 2nd distance in (feet and inches): ");
    scanf("%d%d", &d2.feet, &d2.inches);

    d3.feet = d1.feet + d2.feet;
    d3.inches = d1.inches + d2.inches;

    if (d3.inches >= 12)
    {
        d3.feet += d3.inches / 12;
        d3.inches = d3.inches % 12;
    }

    printf("Sum = %dFeet, %dinches", d3.feet, d3.inches);
}

