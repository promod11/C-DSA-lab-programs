
#include<stdio.h>
#include<ctype.h>
#define max 50
char stack[max],top = -1;
void push(char* ch)
{
    if(top == max-1)
    {
        printf("overflow\n");
        return;
    }
    stack[++top] = *ch;
}
char *pop()
{
    if(top == -1)
    {
        printf("underflow\n");
        return NULL;
    }
    return &stack[top--];
}
int pr(char* ch)
{
    if(*ch == '^')
    {
        return 3;
    }
    else if(*ch == '*' || *ch == '/' || *ch == '%')
    {
        return 2;
    }
    else if(*ch == '+' || *ch == '-')
    {
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    char infix[max],postfix[max];
    int i=0,j=0;
    printf("enter the expression: ");
    fgets(infix,sizeof(infix)/sizeof(char),stdin);
    printf("entered expression is  : %s\n",infix);
    char *ch;
    while(infix[i] != '\0')
        {
            ch = &infix[i++];
            if(isspace(*ch))
            {
                continue;
            }
            else if(isalnum(*ch))
            {
                postfix[j++] = *ch;
            }
            else if(*ch == '(')
            {
                push(ch);
            }
            else{
                if(*ch == ')')
                {
                    while(top != -1 && stack[top] != '(')
                        {
                            postfix[j++]=*pop();
                        }
                        *pop();
                }
                else{
                    while(top !=-1 && stack[top] != '(' && pr(&stack[top]) >= pr(ch))
                        {
                            postfix[j++] = *pop();
                        }
                    push(ch);
                    }
                }
            }
    while(top != -1)
        {
            if(stack[top] == '(')
            {
                *pop();
                continue;
            }
            postfix[j++] = *pop();
        }
    postfix[j] = '\0';
    printf("postfix expression is : %s\n",postfix);
    return 0;
}
