#include <stdio.h>
#include <ctype.h>
#include <string.h>

void push(int *m, int stack[100], int digit)
{
    *m += 1;
    stack[*m] = digit;
}

int pop(int *m, int stack[])
{
    int digit = stack[*m];
    *m -= 1;
    return digit;
}

int operation(int a, int b, char op[])
{
    int result;
    switch (op[0])
    {
    case ('-'):
        result = b - a;
        break;

    case ('+'):
        result = b + a;
        break;

    case ('*'):
        result = b * a;
        break;

    case ('/'):
        result = b / a;
        break;
    }
    return result;
}

int main()
{
    char postfix[100];
    int stack[100], digit = 0;
    int m = -1;

    printf("Enter a postfix expression (give space between each no.): ");
    fgets(postfix, 100, stdin);
    int i = 0, j = 0, result;
    char op[10];

    while (postfix[i] != '\0' && postfix[i] != '\n')
    {
        while (postfix[i] != ' ' && postfix[i] != '\0' && postfix[i] != '\n')
        {
            op[j++] = postfix[i++];
        }
        op[j] = '\0';

        i++;
        j = 0;

        if (isdigit(op[0]))
        {
            while (op[j] != '\0')
            {
                digit = digit * 10 + op[j++] - '0';
            }
            push(&m, stack, digit);
        }

        else
        {
            int a = pop(&m, stack);
            int b = pop(&m, stack);

            result = operation(a, b, op);

            push(&m, stack, result);
        }
        j = 0;
        digit = 0;
    }
    result = pop(&m, stack);
    printf("Result = %d", result);
}