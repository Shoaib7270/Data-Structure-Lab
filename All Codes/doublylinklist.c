#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL, *temp;

void anyposinsert()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    int pos;
    printf("Enter the position:");
    scanf("%d", &pos);
    temp = head;
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    if (pos > c)
    {
        printf("can't insert at %d position\n", pos);
    }
    else
    {
        printf("Enter the data:");
        scanf("%d", newnode->data);
        int i = 0;
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void beginsert()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node *));

    printf("Enter the data:");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("Node Inserted\n");
}
void endinsert()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the data:");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        newnode->prev = NULL;
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        newnode->next = NULL;
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
}
void display()
{
    temp = head;
    printf("NULL <==> ");
    while (temp != NULL)
    {
        printf("%d <==> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
};
int main()
{
    int ch;
    do
    {
        printf("1.Insert from beg\n");
        printf("2.Insert from end\n");
        printf("3.Display\n");
        printf("4.Insert at any position\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            beginsert();
            break;
        case 2:
            endinsert();
            break;
        case 3:
            display();
            break;
        case 4:
            anyposinsert();
            break;
        }
    }
    while (1);
}
