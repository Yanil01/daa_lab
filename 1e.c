// Insertion sort
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

    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        count++;
        count++;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
            count++;
            count++;
            count++;
        }
        arr[j + 1] = temp;
        count++;

        printf("\n Pass %d:\t ", i);
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[j]);
        }
    }
    printf("\n\nFinal sorted array: ");
    count++;
    count++;
    for (i = 0; i < n; i++)
    {
        count++;
        count++;
        printf("%d ", arr[i]);
    }
    count++;
    printf("\n\n Total number of steps: %d\n", count);
    clock_t end_time = clock();
    double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", cpu_time_used);
    return 0;
}