#include <stdio.h>
#include <conio.h>
int a, b, u, v, n, i, j, ne = 1, e, s, d, w;
int visited[10] = {0}, min, mincost = 0, cost[10][10];
void prims()
{
    visited[1] = 1;
    while (ne < n)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            if (visited[i] == 1)
            {
                for (j = 1; j <= n; j++)
                {
                    if (visited[j] == 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        printf("Edge cost from %d to %d : %d\n", a, b, cost[a][b]);
        ne++;
        mincost += cost[a][b];
        visited[b] = 1;
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Minimum cost of spanning tree = %d\n", mincost);
}
void main()
{
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    printf("Enter the number of edges : ");
    scanf("%d", &e);
    for (i = 1; i <= e; i++)
    {
        printf("Enter source : ");
        scanf("%d", &s);
        printf("Enter destination : ");
        scanf("%d", &d);
        printf("Enter weight : ");
        scanf("%d", &w);
        if (s <= 0 || d <= 0 || s > n || d > n || w < 0)
        {
            printf("Invalid data.Try again.\n");
            i--;
            continue;
        }

        cost[s][d] = w;
        cost[d][s] = w;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    printf("The edges of Minimum Cost Spanning Tree are : \n");
    prims();
}
