// Fractional Knapsack
#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0;
    int i, j, total_capacity;
    total_capacity = capacity;

    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }

    for (i = 0; i < n; i++)
    {
        if (weight[i] > total_capacity)
        {
            break;
        }
        else
        {
            x[i] = 1.0;
            tp = tp + profit[i];
            total_capacity = total_capacity - weight[i];
        }
    }

    if (i < n)
    {
        x[i] = total_capacity / weight[i];
        tp = tp + (x[i] * profit[i]);
    }

    printf("\nThe result vector is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%f\t", x[i]);
    }

    printf("\nMaximum profit is: %f", tp);
}

int main()
{
    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;

    printf("\nEnter the no. of objects: ");
    scanf("%d", &num);

    printf("\nEnter the weights and profits of each object: \n");
    for (i = 0; i < num; i++)
    {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("\nEnter the capacity of knapsack: ");
    scanf("%f", &capacity);

    // Calculating ratio and sorting objects by ratio in descending order
    for (i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                // Swap ratio
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                // Swap weight
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                // Swap profit
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    knapsack(num, weight, profit, capacity);

    return 0;
}