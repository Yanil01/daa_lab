// Fibonacci series
#include <stdio.h>
#include <time.h>
int step_count = 0;

void fibonacci(int n)
{
    clock_t start_time;
    double total_time;
    step_count++;
    if (n <= 0)
    {
        printf("Please enter a positive integer.\n");
        return;
    }
    long long a = 0, b = 1;
    step_count++;
    start_time = clock();
    if (n == 1)
    {
        printf("Iteration 1: %lld\n", a);
        step_count++;
    }
    else
    {
        printf("Iteration 1: %lld\n", a);
        step_count++;
        printf("Iteration 2: %lld\n", b);
        step_count++;
        long long next;
        for (int i = 3; i <= n; i++)
        {
            next = a + b;
            step_count++;
            printf("Iteration %d: %lld\n", i, next);
            step_count++;
            a = b;
            b = next;
            step_count++;
        }
    }
    total_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    printf("Total CPU time for fibonacci sequence: %lf seconds\n", total_time);
    printf("Total steps : %d\n", step_count);
}

int main()
{
    int n;
    printf("Enter the number of terms : ");
    scanf("%d", &n);
    step_count++;
    fibonacci(n);
    return 0;
}