#include <stdio.h>
#include <limits.h>

#define MAX 6

int tsp(int cost[MAX][MAX], int dp[1 << MAX][MAX],
        int mask, int pos, int N) {

    if (mask == ((1 << N) - 1)) {
        return cost[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int minCost = INT_MAX;

    for (int village = 0; village < N; village++) {
        if ((mask & (1 << village)) == 0) {
            int newCost = cost[pos][village] +
                tsp(cost, dp, mask | (1 << village),
                    village, N);

            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }

    return dp[mask][pos] = minCost;
}

int main(void) {
    int N;
    int cost[MAX][MAX];
    int dp[1 << MAX][MAX];

    printf("Number of villages: ");
    scanf("%d", &N);

    if (N < 1 || N > MAX) {
        return 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    int minCost = tsp(cost, dp, 1, 0, N);

    printf("The cost list is:\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("\t%d", cost[i][j]);
        }
        printf("\n");
    }

    printf("The Path is:\n");
    printf("1");

    int mask = 1;
    int pos = 0;

    while (mask != (1 << N) - 1) {
        int bestVillage = -1;
        int bestCost = INT_MAX;

        for (int village = 0; village < N; village++) {
            if ((mask & (1 << village)) == 0) {
                int nextMask = mask | (1 << village);

                int currentCost = cost[pos][village] +
                    tsp(cost, dp, nextMask, village, N);

                if (currentCost < bestCost) {
                    bestCost = currentCost;
                    bestVillage = village;
                }
            }
        }

        if (bestVillage == -1) {
            break;
        }

        printf("-->%d", bestVillage + 1);

        mask |= (1 << bestVillage);
        pos = bestVillage;
    }

    printf("-->1\n");
    printf("Minimum cost is %d\n", minCost);

    return 0;
}
