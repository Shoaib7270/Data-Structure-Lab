#include <stdio.h>
#include <stdlib.h>
#define N 100

int queue[N];
int rare = -1;
int front = -1;

void insert(int x)
{
	if (rare == N - 1)
	{
		printf("Overflow condition");
	}

	else if (rare == -1 && front == -1)
	{
		rare = front = 0;
		queue[rare] = x;
	}
	else
	{
		rare++;
		queue[rare] = x;
	}
}
void delete ()
{
	if (rare == -1 && front == -1)
	{
		printf("THE QUEUE IS EMPTY");
	}
	else if (rare == front)
	{
		rare = front = -1;
	}
	else
	{
		printf("The deleted iteam is %d\n", queue[front]);
		front++;
	}
}
void display()
{
	if (rare == -1 && front == -1)
	{
		printf("THE QUEUE IS EMPTY\n");
	}
	else
	{
		for (int i = front; i < rare + 1; i++)
		{
			printf("%d ", queue[i]);
		}
	}
}
int main()
{
	int choice, n;
	while (1)
	{

		printf("\n1.Insert\n");
		printf("2.delete\n");
		printf("3.display\n");
		printf("4.Exit\n");
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter your desire number to insert : ");
			scanf("%d", &n);
			insert(n);
			break;

		case 2:
			delete ();
			break;

		case 3:
			display();
			break;
		case 4:
			exit(1);
		}
	}
}
