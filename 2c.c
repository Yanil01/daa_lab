// Merge Sort with Step Count and Time Analysis
#include <stdio.h>
#include <time.h>

int step_count = 0;

// Function to print subarray
void printSubArray(int a[], int beg, int end)
{
    printf("[ ");
    for (int i = beg; i <= end; i++)
    {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

// Merge function
void merge(int a[], int beg, int mid, int end)
{
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int L[n1], R[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[beg + i];
        step_count++;
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = a[mid + 1 + j];
        step_count++;
    }

    int i = 0, j = 0, k = beg;

    // Merge the temp arrays
    while (i < n1 && j < n2)
    {
        step_count++;
        if (L[i] <= R[j])
        {
            a[k++] = L[i++];
        }
        else
        {
            a[k++] = R[j++];
        }
    }

    // Copy remaining elements
    while (i < n1)
    {
        a[k++] = L[i++];
        step_count++;
    }

    while (j < n2)
    {
        a[k++] = R[j++];
        step_count++;
    }
}

// Merge Sort function
void mergeSort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;

        printf("\nDividing Array: ");
        printSubArray(a, beg, end);

        // sort left half first
        mergeSort(a, beg, mid);

        // then right half
        mergeSort(a, mid + 1, end);

        // merge both halves
        merge(a, beg, mid, end);

        printf("After Merging: ");
        printSubArray(a, beg, end);

        step_count++;
    }
}

// Print full array
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}

// Main function
int main()
{
    int a[200], n;
    clock_t start_time, end_time;
    double total_time;

    printf("How many array elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        step_count++;
    }

    printf("\nBefore sorting:\n");
    printArray(a, n);

    start_time = clock();

    mergeSort(a, 0, n - 1);

    end_time = clock();

    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nAfter sorting:\n");
    printArray(a, n);

    printf("\n---- Analysis ----\n");
    printf("Total steps: %d\n", step_count);
    printf("CPU Time: %f seconds\n", total_time);
    printf("Time complexity: O(n log n)\n");
    printf("Space complexity: O(n)\n");

    return 0;
}