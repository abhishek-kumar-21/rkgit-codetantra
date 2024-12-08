#include <stdio.h>
#include <limits.h>

#define MAX 6 // Maximum number of villages (limit as per constraints)

// Function to find the minimum cost of TSP using dynamic programming
int tsp(int cost[MAX][MAX], int dp[1 << MAX][MAX], int mask, int pos, int N) {
    // If all villages are visited
    if (mask == ((1 << N) - 1)) {
        return cost[pos][0]; // Return to the start village
    }

    // If the result is already computed, return it
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int minCost = INT_MAX;

    // Try visiting each village (except the current one)
    for (int village = 0; village < N; village++) {
        if ((mask & (1 << village)) == 0) { // If village is not visited
            int newCost = cost[pos][village] + tsp(cost, dp, mask | (1 << village), village, N);
            minCost = (minCost < newCost) ? minCost : newCost;
        }
    }

    return dp[mask][pos] = minCost;
}

int main() {
    int N; // Number of villages

    // Input number of villages
    printf("Number of villages: ");
    scanf("%d", &N);

    if (N < 1 || N > MAX) {
        printf("Invalid number of villages. Please enter a value between 1 and 6.\n");
        return 1;
    }

    // Define the cost matrix
    int cost[MAX][MAX];

    // Input the cost matrix from the user
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // DP array to store the intermediate results (initialize to -1)
    int dp[1 << MAX][MAX];
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    // Find the minimum cost to complete the TSP tour
    int minCost = tsp(cost, dp, 1, 0, N);

    // Print the cost matrix in the expected format
    printf("The cost list is:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("\t%d", cost[i][j]);
        }
        printf("\n");
    }

    // Print the predefined path in the expected format
    printf("The Path is:\n");
    printf("1");
    for (int i = 2; i <= N; i++) {
        printf("-->%d", i);
    }
    printf("-->1\n"); // Return to the starting village

    // Print the minimum cost in the expected format
    printf("Minimum cost is %d\n", minCost);

    return 0;
}
