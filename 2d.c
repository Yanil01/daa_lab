#include <stdio.h>
#include <time.h>

int step_count = 0;

void printSubArray(int a[], int low, int high)
{
    int i;
    step_count++;

    printf("[");
    for (i = low; i <= high; i++)
    {
        printf("%d ", a[i]);
    }
    printf("]\n");

    step_count++;
}

int Partition(int a[], int low, int high)
{
    step_count++;

    int pivot = a[low];
    step_count++;

    int i = low + 1;
    int j = high;
    step_count += 2;

    printf("\n Pivot = %d | Dividing: ", pivot);
    printSubArray(a, low, high);

    while (i <= j)
    {
        step_count++;

        while (i <= high && a[i] <= pivot)
        {
            step_count += 2;
            i++;
            step_count++;
        }

        while (a[j] > pivot)
        {
            step_count += 2;
            j--;
            step_count++;
        }

        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            step_count += 3;
        }
    }

    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    step_count += 3;

    return j;
}

void quicksort(int a[], int low, int high)
{
    step_count++;

    if (low < high)
    {
        int pi = Partition(a, low, high);
        step_count++;

        printf("Left subarray: ");
        printSubArray(a, low, pi - 1);

        printf("Right subarray: ");
        printSubArray(a, pi + 1, high);

        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}

void PrintArray(int a[], int n)
{
    int i;
    step_count++;

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    step_count++;
    printf("\n");
}

int main()
{
    int a[200], n, i;
    clock_t start_time, end_time;
    double total_time;

    step_count++;

    printf("How many array elements: ");
    scanf("%d", &n);
    step_count++;

    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        step_count++;
    }
    step_count++;

    printf("\nBefore sorting: \n");
    PrintArray(a, n);

    start_time = clock();
    quicksort(a, 0, n - 1);
    end_time = clock();

    step_count++;

    printf("\nAfter sorting: \n");
    PrintArray(a, n);

    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n--- Analysis ---\n");
    printf("Total steps: %d\n", step_count);
    printf("CPU time: %lf seconds\n", total_time);
    printf("Time Complexity: \n");
    printf("Best/Average: O(n log n)\n");
    printf("Worst: O(n^2)\n");
    printf("Space Complexity: O(log n)\n");

    return 0;
}