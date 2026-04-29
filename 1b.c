// GCD
#include <stdio.h>
#include <time.h>
int step_count = 0;
int gcd(int a, int b)
{
    int r;
    step_count++;
    while (b != 0)
    {
        step_count++;
        r = a % b;
        step_count++;
        a = b;
        step_count++;
        b = r;
        step_count++;
    }
    step_count++;
    return a;
}
int main()
{
    int num1, num2;
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);
    step_count++;
    if (num1 == 0 || num2 == 0)
    {
        printf("GCD is not defined for zero.\n");
        step_count++;
        return 0;
    }
    clock_t start_time = clock();
    if (num1 == 0)
    {
        printf("GCD : %d\n", num2);
        step_count++;
    }
    else if (num2 == 0)
    {
        printf("GCD : %d\n", num1);
        step_count++;
    }
    else
    {
        printf("GCD : %d\n", gcd(num1, num2));
        step_count++;
    }
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    printf("Total steps: %d\n", step_count);
    return 0;
}