// N-queen problem
#include <stdio.h>
#include <stdbool.h>

#define N 8

int board[N][N];

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int row, int col)
{
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

// A recursive utility function to solve N Queen problem
bool solveNQ(int col)
{
    // If all queens are placed, then return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col))
        {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQ(col + 1))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution
            // then remove queen from board[i][col] (Backtrack)
            board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column col then return false
    return false;
}

// A utility function to print solution
void printSolution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    if (solveNQ(0) == false)
    {
        printf("Solution does not exist\n");
        return 0;
    }

    printSolution();
    return 0;
}