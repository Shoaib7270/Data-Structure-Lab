#include <stdio.h>
#include <stdlib.h>
#define N 100
int stack[N];
int top = -1;
void push(int x)
{

    if (top == N - 1)
    {
        printf("Overflow condition ");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("the element is %d", stack[top]);
        top--;
    }
}
void display()
{
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d", stack[top]);
        }
    }
}
int main()
{
    int choice, x;
    while (1)
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element that you want to insert in the stack : ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);

        default:
            break;
        }
    }

    return 0;
}
