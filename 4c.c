#include <stdio.h>

int isSubsetSum(int set[], int n, int sum, int subset[], int subsetSize)
{
    // If sum is 0, then a subset is found
    if (sum == 0)
    {
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++)
        {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return 1;
    }

    // If no more elements left and sum is not 0
    if (n == 0 && sum != 0)
    {
        return 0;
    }

    // If the last element is greater than sum, then ignore it
    if (set[n - 1] > sum)
    {
        return isSubsetSum(set, n - 1, sum, subset, subsetSize);
    }

    /* Check if sum can be obtained by any of the following:
       (a) including the last element
       (b) excluding the last element */
    subset[subsetSize] = set[n - 1];
    return isSubsetSum(set, n - 1, sum - set[n - 1], subset, subsetSize + 1) ||
           isSubsetSum(set, n - 1, sum, subset, subsetSize);
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum;
    int n = sizeof(set) / sizeof(set[0]);
    int subset[n];

    printf("Enter the sum to check: ");
    scanf("%d", &sum);

    if (!isSubsetSum(set, n, sum, subset, 0))
    {
        printf("No subset with given sum.\n");
    }

    return 0;
}