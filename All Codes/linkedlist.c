#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *temp;

void lastinsert()
{
    struct node *newnode;
    int item;
    newnode = (struct node *)malloc(sizeof(struct node *)); // memory alocation
    if (newnode == NULL)
    {
        printf("List is full");
    }
    else
    {
        printf("enter the data:");
        scanf("%d", &item);
        newnode->data = item;

        if (head == NULL)
        {
            newnode->next = NULL;
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            newnode->next = NULL;
            printf("Inserted");
        }
    }
}
void insertaianyposition()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node *));
    int pos, i = 1;
    printf("\nEnter the position you want to Add:");
    scanf("%d", &pos);

    printf("\nEnter the data:");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
        printf("\nNode Inserted At 1st Position.");
    }
    else
    {
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        printf("\nNode Inserted At %dth Position.", pos);
    }
}
void beginsert()
{
    struct node *newnode;
    int item, n;
    newnode = (struct node *)malloc(sizeof(struct node *)); // memory alocation
    if (newnode == NULL)
    {
        printf("List is full");
    }
    else
    {
        printf("enter the data:");
        scanf("%d", &newnode->data);
        // newnode->data;
        newnode->next = head;
        head = newnode;
        printf("\nNode Inserted\n");
    }
}
void display()
{

    struct node *ptr;
    int count = 0;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("\nelements are: ");
            printf("%d ", ptr->data);
            ptr = ptr->next;
            count++;
        }
        printf("\nThere are %d elements", count);
    }
}
void search()
{
    // struct node *temp;
    int x, c = 0;
    printf("\nenter the data you want to found:");
    scanf("%d", &x);
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            c++;
            break;
        }
        temp = temp->next;
    }
    if (c != 0)
    {
        printf("founded\n");
    }
    else
    {
        printf("not found\n");
    }
}
void delet()
{
    struct node *nextnode;
    int pos, i = 1;
    printf("\nenter the position you want to delete:");
    scanf("%d", &pos);

    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}
void deletfrombeg()
{
    // struct node *temp;
    if (head == NULL)
    {
        printf("\nList is Already Empty");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteformend()
{
    struct node *previous;
    temp = head;
    while (temp->next != NULL)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;
    free(temp);
}
// Sort the linked list
void sortLinkedList()
{
    struct node *current = head;
    struct node *index = NULL;
    int temp;

    if (head == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            // index points to the node next to current
            index = current->next;

            while (index != NULL)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
        printf("\n\t\t\tSorted!");
    }
}
int main()
{
    int ch;

    do
    {
        printf("\n1.Insert from Beg \n");
        printf("2.Insert from end \n");
        printf("3.Delete from Beg \n");
        printf("4.Delete a specific elements \n");
        printf("5.Search elements \n");
        printf("6.Display \n");
        printf("7.Delete from end \n");
        printf("8.Sort The Elements \n");
        printf("9.Insert at any Position \n");
        printf("Enter your choice \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            deletfrombeg();
            break;
        case 4:
            delet();
            break;
        case 5:
            search();
            break;
        case 6:
            display();
            break;
        case 7:
            deleteformend();
            break;
        case 8:
            sortLinkedList();
            break;
        case 9:
            insertaianyposition();
            break;
        default:
            printf("Invalied choice!");
        }
    } while (1);
    return 0;
}
/*
void modify(){
    struct node *c;
int id,count=0;
printf("\nEnter the Id you want to modify:");
scanf("%d",&id);
temp=head;
while(temp!=NULL){
    if(temp->data == id){
        c=temp;
        count++;
        break;
    }
    temp=temp->next;
}
if(count!=0){
    printf("Founded\n");
    Printf("Enter The Number:");
    scanf("%d",&c->data);
}else{
printf("Not found\n");
}
}
*/
