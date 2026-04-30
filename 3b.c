#include <stdio.h>

#define MAX 100

typedef struct Job
{
    char id[5];
    int deadline;
    int profit;
} Job;

int minvalue(int x, int y)
{
    if (x < y)
        return x;
    return y;
}

void jobsequencingwithDeadline(Job jobs[], int n)
{
    int i, j, k, maxprofit;
    int timeslot[MAX];
    int filledTimeslot = 0;
    int dmax = 0;

    // Find the maximum deadline
    for (i = 0; i < n; i++)
    {
        if (jobs[i].deadline > dmax)
        {
            dmax = jobs[i].deadline;
        }
    }

    // Initialize all time slots to empty (-1)
    for (i = 1; i <= dmax; i++)
    {
        timeslot[i] = -1;
    }

    printf("dmax: %d\n", dmax);

    // Schedule jobs greedily
    for (i = 0; i < n; i++)
    {
        k = minvalue(dmax, jobs[i].deadline);
        while (k >= 1)
        {
            if (timeslot[k] == -1)
            {
                timeslot[k] = i;
                filledTimeslot++;
                break;
            }
            k--;
        }

        if (filledTimeslot == dmax)
            break;
    }

    // Display required jobs
    printf("\nRequired jobs: ");
    for (i = 1; i <= dmax; i++)
    {
        if (timeslot[i] != -1)
        {
            printf("%s ", jobs[timeslot[i]].id);
            if (i < dmax)
                printf("--> ");
        }
    }

    // Calculate and display total profit
    maxprofit = 0;
    for (i = 1; i <= dmax; i++)
    {
        if (timeslot[i] != -1)
        {
            maxprofit += jobs[timeslot[i]].profit;
        }
    }
    printf("\nMax Profit: %d\n", maxprofit);
}

int main(void)
{
    int i, j;
    Job jobs[5] = {
        {"j1", 2, 100},
        {"j2", 1, 27},
        {"j3", 2, 15},
        {"j4", 1, 10}};

    int n = 4;
    Job temp;

    // Sort jobs based on profit in descending order (Bubble Sort)
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (jobs[j + 1].profit > jobs[j].profit)
            {
                temp = jobs[j + 1];
                jobs[j + 1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    // Print sorted job list
    printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for (i = 0; i < n; i++)
    {
        printf("%10s %10d %10d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }

    jobsequencingwithDeadline(jobs, n);

    return 0;
}