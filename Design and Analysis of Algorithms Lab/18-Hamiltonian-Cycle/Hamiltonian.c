#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int V;

void printSolution(int path[]);

// Check if the current vertex can be added to the solution path
bool isSafe(int v, bool** graph, int path[], int pos)
{
    // Check if the vertex is adjacent to the previous vertex in the path
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive utility function to find a Hamiltonian Cycle
bool hamCycleUtil(bool** graph, int path[], int pos)
{
    // If all vertices are included in the path
    if (pos == V)
    {
        // Check if there is an edge from the last vertex to the first
        return graph[path[pos - 1]][path[0]] == 1;
    }

    // Try different vertices as the next candidate
    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamCycleUtil(graph, path, pos + 1))
                return true;

            // Backtrack if adding vertex v doesn't lead to a solution
            path[pos] = -1;
        }
    }

    return false;
}

// Solves the Hamiltonian Cycle problem and prints the result
bool hamCycle(bool** graph)
{
    int* path = (int*) malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start at the first vertex
    path[0] = 0;

    if (hamCycleUtil(graph, path, 1) == false)
    {
        printf("Solution does not exist");
        free(path);
        return false;
    }

    printSolution(path);
    free(path);
    return true;
}

// Print the solution path
void printSolution(int path[])
{
    printf("Following is one Hamiltonian Cycle: \n");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); // Print the starting vertex again to show the cycle
}

int main()
{
    printf("Number of vertices: ");
    scanf("%d", &V);

    bool** graph = (bool**) malloc(V * sizeof(bool*));
    for (int i = 0; i < V; i++)
        graph[i] = (bool*) malloc(V * sizeof(bool));

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    hamCycle(graph);

    for (int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
