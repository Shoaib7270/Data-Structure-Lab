#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf(" %d ", a[i]);
}
void linearsearch(int a[], int n)
{
    int x, po = -1;
    printf("\nenter the data you want to search:");
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            po = i + 1;
            break;
        }
    }
    if (po != -1)
    {
        printf("\nData founded in %d poistion in array:", po);
    }
    else
    {
        printf("Data not founded");
    }
}
void binarysearch(int a[], int n)
{
    int x, po = -1, beg, end, mid;
    beg = 0;
    end = n - 1;
    printf("\nenter the data you want to search:");
    scanf("%d", &x);
    while (beg < end)
    {
        mid = (beg + end) / 2;
        if (a[mid] == x)
        {
            po = mid;
            break;
        }
        else if (a[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }
    if (po != -1)
    {
        printf("\ndata founded in %d position", po + 1);
    }
    else
    {
        printf("\nnot founded");
    }
}
void boublesort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("\nSorted:- ");
}
void selectionsort(int a[], int n)
{
    int i, j, min;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    printf("\nsorted:-");
}
void insertionsort(int a[], int n)
{
    int i, j, item;
    for (i = 1; i < n; i++)
    {
        item = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > item)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = item;
    }
    printf("\nsorted :");
}

int partition(int a[], int beg, int end)
{
    int i, j, pivot, temp;
    // pivot=beg;
    i = beg;
    j = end;
    pivot = end;
    while (i < j)
    {
        while (a[i] <= a[pivot])
            i++;
        while (a[j] > a[pivot])
            j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[pivot];
    a[pivot] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int pi = partition(a, beg, end);
        quicksort(a, beg, pi - 1);
        quicksort(a, pi + 1, end);
    }
}

void marge(int a[], int l, int m, int r)
{
    int i, j, k, n1, n2;
    n1 = m - l + 1;
    n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void margesort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        margesort(a, l, m);
        margesort(a, m + 1, r);
        marge(a, l, m, r);
    }
}

void insert(int a[], int n)
{
    int i, x, lo;
    printf("enter the value and position you want to add:");
    scanf("%d%d", &x, &lo);
    for (i = n; i >= lo; i--)
    {
        a[i] = a[i - 1];
    }
    n++;
    a[lo - 1] = x;
    printf("inserted\n");
    printf("\nArray elements are: ");
    for (i = 0; i < n; i++)
        printf("%d", a[i]);
}


int main()
{
    int a[SIZE], n, i;
    printf("enter the size of array:");
    scanf(" %d", &n);
    for (i = 0; i < n; i++)
    {
        printf("%d th element:", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Array Elements are: ");
    printarray(a, n);

    int ch;
    do
    {
        printf("\n1.Insert Element.");
        printf("\n2.Linear Search.");
        printf("\n3.Binary Search.");
        printf("\n4.Bouble sort.");
        printf("\n5.Selection Sort.");
        printf("\n6.Insertion Sort.");
        printf("\n7.Quick Sort.");
        printf("\n8.Marge Sort.\n\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(a, n);
            n++;
            printf("\nArray inserted");
            break;

        case 2:
            linearsearch(a, n);
            break;
        case 3:
            binarysearch(a, n);
            break;
        case 4:
            boublesort(a, n);
            printf("\nSorted Array:- ");
            printarray(a, n);
            break;
        case 5:
            selectionsort(a, n);
            printf("\nSorted Array:- ");
            printarray(a, n);
            break;
        case 6:
            insertionsort(a, n);
            printf("\nSorted Array:- ");
            printarray(a, n);
            break;
        case 7:
            quicksort(a, 0, n - 1);
            printf("\nSorted Array:- ");
            printarray(a, n);
            break;
        case 8:
            margesort(a, 0, n - 1);
            printf("\nSorted Array:- ");
            printarray(a, n);
            break;
        case 9:
            printf("\nArray Elements are: ");
            printarray(a, n);
            break;
        default:
            printf("Invalied choice!");
            break;
        }
    } while (1);
}
