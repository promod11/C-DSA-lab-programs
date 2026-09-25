# include<stdio.h>
#define max 50
int st[max],top=-1;
void push(int *el);
int *pop();
int *peek();
void display();
int main()
{
    int n;
    int choice;
    do{
        printf("-----STACK OPERATIONS-----\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("--------------------------\n");
        printf("enter the choice : ");

        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter an element : ");
                scanf("%d",&n);
                push(&n);
                break;
            case 2:
                printf("%d\n",*pop());
                break;
            case 3:
                printf("top element : %d\n",*peek());
                break;
            case 4:
                display();
                break;
        }
    }while(choice != 5);
    printf("final stack elements : ");
    for(int i= top;i>=0;i--)
    {
        printf("%d ",st[i]);
    }
    printf("\n");
    return 0;
}
void push(int *el)
{
    if(top == max-1)
    {
        printf("overflow\n");
    }
    st[++top]= *el;
}
int *pop()
{
    if(top == -1)
    {
        printf("underflow\n");
        return 0;
    }
    return &st[top--];
}
int *peek()
{
    if(top == -1)
    {
        printf("stack is empty\n");
        return 0;
    }
    return &st[top];
}
void display()
{
    for(int i=top;i>=0;i--)
    {
        printf("%d ",st[i]);
    }
    printf("\n");
}