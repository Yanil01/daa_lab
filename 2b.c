// min-max algorithm
#include <stdio.h>
#include <time.h>
int step_count = 0;
struct minmax
{
    int min;
    int max;
};
struct minmax find_min_max(int A[], int l, int r)
{
    struct minmax result, left, right;
    step_count++;
    step_count++;
    if (l == r)
    {
        result.min = A[l];
        step_count++;
        result.max = A[l];
        step_count++;
        printf("Single element [%d] -> min: %d, max: %d\n", A[l], result.min, result.max);
        step_count++;
        return result;
    }
    step_count++;
    if (r == l + 1)
    {
        step_count++;
        if (A[l] < A[r])
        {
            result.min = A[l];
            step_count++;
            result.max = A[r];
            step_count++;
        }
        else
        {
            result.min = A[r];
            step_count++;
            result.max = A[l];
            step_count++;
        }
        printf("Comparing [%d %d] -> min: %d, max: %d\n", A[l], A[r], result.min, result.max);
        step_count++;
        return result;
    }
    int mid = l + (r - l) / 2;
    step_count++;
    printf("\n Dividing : Index [%d %d] and [%d %d]\n", l, mid, mid + 1, r);
    step_count++;
    left = find_min_max(A, l, mid);
    step_count++;
    right = find_min_max(A, mid + 1, r);
    step_count++;
    step_count++;
    result.min = (left.min < right.min) ? left.min : right.min;
    step_count++;
    result.max = (left.max > right.max) ? left.max : right.max;
    step_count++;
    printf("Combining [%d - %d] -> min: %d, max: %d\n", l, r, result.min, result.max);
    step_count++;
    return result;
}
int main()
{
    int A[200], n, i;
    struct minmax finalResult;
    clock_t start_time, end_time;
    double total_time;
    step_count++;
    printf("How many elements: ");
    scanf("%d", &n);
    step_count++;
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        step_count++;
    }
    start_time = clock();
    finalResult = find_min_max(A, 0, n - 1);
    end_time = clock();
    step_count++;
    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    step_count++;
    printf("\n ---Final Result---\n");
    printf("minimum element: %d\n", finalResult.min);
    printf("maximum element: %d\n", finalResult.max);
    step_count + 2;
    printf("\n---Analysis---\n");
    printf("Total steps : %d\n", step_count);
    printf("Total CPU time for min-max algorithm: %1f seconds\n", total_time);
    printf("Time complexity: O(n)\n");
    printf("Space complexity: O(log n) due to recursive stack space\n");
    return 0;
}
