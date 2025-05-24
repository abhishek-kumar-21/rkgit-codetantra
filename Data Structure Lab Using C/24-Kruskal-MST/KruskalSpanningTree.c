#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int i, j, k, a, b, u, v, n, e, s, d, w, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];
int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}
int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
void kruskal()
{
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            printf("Edge cost from %d to %d : %d\n", a, b, min);
            mincost += min;
            ne++;
        }
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
    kruskal();
}
