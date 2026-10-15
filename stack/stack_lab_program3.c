#include <stdio.h>
#include <ctype.h>

#define max 50

int stack[max], top = -1;

void push(int *ch)
{
    if (top == max - 1)
    {
        printf("Overflow\n");
        return;
    }

    stack[++top] = *ch;
}

int *pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return NULL;
    }

    return &stack[top--];
}

int main()
{
    char exp[max];
    int n1, n2, n3, i = 0;
    int *p;

    printf("Enter the postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    while (exp[i] != '\0')
    {
        char ch = exp[i++];

        if (isspace(ch))
            continue;

        if (isdigit(ch))
        {
            n3 = ch - '0';
            push(&n3);
        }
        else
        {
            n1 = *pop();
            n2 = *pop();
            switch (ch)
            {
                case '+':
                    n3 = n2 + n1;
                    break;

                case '-':
                    n3 = n2 - n1;
                    break;

                case '*':
                    n3 = n2 * n1;
                    break;

                case '/':
                    n3 = n2 / n1;
                    break;
            }
            push(&n3);
        }
    }

    printf("Result of postfix expression: %d\n", stack[top]);

    return 0;
}
