#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool isPlayer1Turn = true;

    while (true)
    {
        displayBoard();
        if(isPlayer1Turn)
        {
            printf("Player 1's turn (X): ");
        }
        else
        {
            printf("Player 2's turn (O): ");
        }
    }

    return 0;
}

int displayBoard()
{
    int grid[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int rows = sizeof(grid) / sizeof(grid[0]);
    int columns = sizeof(grid[0]) / sizeof(grid[0][0]);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("| %d  ", grid[i][j]);
        }
        printf("|");
        printf("\n");
    }
    return 0;
}

