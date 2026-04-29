// Selection sort
#include <stdio.h>
#include <time.h>

int main()
{
    int n, arr[50], i, j, temp, count = 0;
    count++;
    printf("Enter total number of elements: ");
    count++;
    scanf("%d", &n);
    count++;

    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        count++;
        count++;
        count++;
    }

    count++;
    clock_t start_time = clock();

    for (i = 0; i < n - 1; i++)
    {
        count++;
        count++;
        count++;
        int min_idx = i;

        for (j = i + 1; j < n; j++)
        {
            count++;
            count++;
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
                count++;
            }
        }

        if (min_idx != i)
        {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            count++;
            count++;
            count++;
        }

        printf("\n Pass %d:\t ", i + 1);
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[j]);
        }
    }

    printf("\n\n Final sorted array: ");
    count++;
    count++;

    for (i = 0; i < n; i++)
    {
        count++;
        count++;
        printf("%d ", arr[i]);
    }

    count++;
    printf("\n Total number of steps: %d\n", count);

    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}