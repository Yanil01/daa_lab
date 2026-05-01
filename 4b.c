#include <stdio.h>

#define MAX 100

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n, int k[MAX][MAX])
{
    int i, w;
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if (wt[i - 1] <= w)
                k[i][w] = max(val[i - 1] + k[i - 1][w - wt[i - 1]], k[i - 1][w]);
            else
                k[i][w] = k[i - 1][w];
        }
    }
    return k[n][W];
}

void printItems(int k[MAX][MAX], int wt[], int val[], int n, int w)
{
    int res = k[n][w];
    printf("Selected items:\n");
    for (int i = n; i > 0 && res > 0; i--)
    {
        if (res == k[i - 1][w])
            continue;
        else
        {
            printf("Item %d (Weight = %d, Value = %d)\n", i, wt[i - 1], val[i - 1]);
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int w = 50;
    int n = 3;
    int k[MAX][MAX];

    int maxProfit = knapsack(w, wt, val, n, k);
    printf("Maximum Profit = %d\n", maxProfit);
    printItems(k, wt, val, n, w);

    return 0;
}