// Binary search
#include <stdio.h>
#include <time.h>
int step_count = 0;
int binary_search(int arr[], int left, int right, int key)
{
    step_count++;
    if (left > right)
    {
        step_count++;
        return -1; // Key not found
    }
    int mid = left + (right - left) / 2;
    step_count++;
    if (arr[mid] == key)
    {
        step_count++;
        return mid; // Key found at index mid
    }
    step_count++;
    if (arr[mid] > key)
    {
        printf("Key < %d, searching in left half\n", arr[mid]);
        return binary_search(arr, left, mid - 1, key); // Search in left half
    }
    else
    {
        printf("Key > %d, searching in right half\n", arr[mid]);
        return binary_search(arr, mid + 1, right, key); // Search in right half
    }
}
int main()
{
    int n, key;
    clock_t start_time;
    double total_time;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    step_count++;
    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        step_count++;
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    step_count++;
    start_time = clock();
    int result = binary_search(arr, 0, n - 1, key);
    total_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    if (result != -1)
    {
        printf("Key found at index: %d\n", result);
    }
    else
    {
        printf("Key not found\n");
    }
    printf("Total CPU time for binary search: %1f seconds\n", total_time);
    printf("Total steps: %d\n", step_count);
    return 0;
}