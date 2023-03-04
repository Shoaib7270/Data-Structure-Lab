#include <stdio.h>
int main()
{
    int cost[10][10], visited[10] = {0}, min, i, j, b, a, n, e_no = 1, min_cost = 0;
    printf("Enter the number of vertex:");
    scanf("%d", &n);
    printf("Enter the form of adjacency matrix\n");

    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= n; j++)
        {

            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
            {
                cost[i][j] = 1000;
            }
        }
    }

    //	visited[1] = 1;

    while (e_no < n)
    {

        min = 1000;

        for (i = 1; i <= n; i++)
        {

            for (j = 1; j <= n; j++)
            {

                if (cost[i][j] < min)
                {

                    if (visited[i] == 0)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (visited[b] == 0 || visited[a] == 0)
        {
            printf("\n%d to %d  cost=%d", a, b, min);
            min_cost = min_cost + min;
            e_no++;
        }
        visited[a] = 1;
        visited[b] = 1;

        cost[a][b] = cost[b][a] = 1000;
    }
    printf("\nminimum weight is %d", min_cost);
    return 0;
}
