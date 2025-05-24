#include <limits.h>
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
    for (i = 1; i <= n; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindistance = INFINITY;
        for (i = 1; i <= n; i++)
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        visited[nextnode] = 1;
        for (i = 1; i <= n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }
    printf("Node\tDistance\tPath\n");
    for (i = 1; i <= n; i++)
        if (i != startnode)
        {
            if (distance[i] == INFINITY)
            {
                printf("%4d\t%8s", i, "INF");
                printf("\tNO PATH\n");
            }
            else
            {
                printf("%4d\t%8d", i, distance[i]);
                printf("\t%d", i);
                j = i;
                do
                {
                    j = pred[j];
                    printf("<-%d", j);
                } while (j != startnode);
                printf("\n");
            }
        }
}

int main()
{
    int s, d, w, i, j;
    printf("Enter the number of vertices : ");
    scanf("%d", &V);
    printf("Enter the number of edges : ");
    scanf("%d", &E);
    for (i = 1; i <= V; i++)
    {
        for (j = 1; j <= V; j++)
        {
            graph[i][i] = 0;
        }
    }
    for (i = 1; i <= E; i++)
    {
        printf("Enter source : ");
        scanf("%d", &s);
        printf("Enter destination : ");
        scanf("%d", &d);
        printf("Enter weight : ");
        scanf("%d", &w);
        if (s > V || d > V || s <= 0 || d <= 0)
        {
            printf("Invalid index. Try again.\n");
            i--;
            continue;
        }
        else
        {
            graph[s][d] = w;
        }
    }
    printf("Enter the source :");
    scanf("%d", &s);
    dijkstra(graph, V, s);
    return 0;
}
