#include <stdio.h>

struct complex
{
    float imaginary;
    float real;
};
typedef struct complex complex;

complex complex_sum(complex s1, complex s2)
{
    complex temp;

    temp.imaginary = s1.imaginary + s2.imaginary;
    temp.real = s1.real + s2.real;

    return temp;
}

int main()
{
    complex s1, s2, result;

    printf("Enter the real and imaginary part : ");
    scanf("%f%f", &s1.real, &s1.imaginary);

    printf("Enter the real and imaginary part : ");
    scanf("%f%f", &s2.real, &s2.imaginary);

    result = complex_sum(s1, s2);

    printf("Result = %.2f + %.2fi", result.real, result.imaginary);
}