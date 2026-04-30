#include <stdio.h>
#include <time.h>

int step_count = 0;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    step_count++;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    step_count++;

    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    step_count++;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        step_count++;
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    int i;
    printf("\n--- Building max Heap (Divide Phase) ---\n");
    for (i = n / 2 - 1; i >= 0; i--)
    {
        printf("Heapify subtree rooted at index %d\n", i);
        heapify(arr, n, i);
        step_count++;
    }

    printf("\n--- Extracting elements (Conquer Phase) ---\n");
    for (i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        step_count++;
        printf("Dividing: heap size = %d | Sorted Part = [%d - %d]\n", i, i, n - 1);
        heapify(arr, i, 0);
    }
}

void PrintArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[200], n, i;
    clock_t start_time, end_time;
    double total_time;

    printf("How many array elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    step_count++;

    printf("\nBefore Sorting: \n");
    PrintArray(arr, n);

    start_time = clock();
    heapsort(arr, n);
    end_time = clock();

    printf("\nAfter Sorting: \n");
    PrintArray(arr, n);

    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n--- Analysis ---\n");
    printf("Total steps : %d\n", step_count);
    printf("Total CPU time : %lf seconds\n", total_time);
    printf("Time Complexity: O(n log n)\n");
    printf("Space Complexity: O(1) (In-Place)\n");

    return 0;
}