#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int evaluatePostfix(char P[])
{

    int i = 0;
    int a, b, result;

    while (P[i] != '\0')
    {

        if (isdigit(P[i]))
        {
            push(P[i] - '0');
        }

        else
        {

            a = pop();
            b = pop();

            switch (P[i])
            {

            case '+':
                result = b + a;
                break;
            case '-':
                result = b - a;
                break;
            case '*':
                result = b * a;
                break;
            case '/':
                result = b / a;
                break;
            case '^':
                result = pow(b, a);
                break;
            }

            push(result);
        }

        i++;
    }

    return pop();
}

int main()
{

    char P[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", P);

    int value = evaluatePostfix(P);

    printf("Value = %d", value);

    return 0;
}