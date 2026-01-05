#include <stdio.h>
#include <stdbool.h>

void displayBoard();

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

        char choice;
        scanf(" %c", &choice);

        //validando se a escolha é um número de 1 a 9
        if(choice < '1' || choice > '9')
        {
            printf("Invalid choice. Please choose a number between 1 and 9.\n");
            continue;
        }
        // Alterna o turno 
        isPlayer1Turn = !isPlayer1Turn;
    }

    return 0;
}

void displayBoard()
{
    int grid[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int rows = 3;
    int columns = 3;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("| %d  ", grid[i][j]);
        }
        printf("|\n");
    }
}