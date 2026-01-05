#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void displayBoard();

int main()
{
    bool isPlayer1Turn = true;

    while (true)
    {
        displayBoard();

        if (isPlayer1Turn)
        {
            printf("Player 1's turn (X): ");
        }
        else
        {
            printf("Player 2's turn (O): ");
        }

        char choice;
        scanf(" %c", &choice);

        if (choice < '1' || choice > '9')
        {
            printf("Invalid choice. Please choose a number between 1 and 9.\n");
            continue;
        }

        // Convertendo char para índice da matriz
        int choiceNum = choice - '0'; 
        int row = (choiceNum - 1) / 3; // Cálculo da linha
        int col = (choiceNum - 1) % 3; // Cálculo da coluna

        // Verifica se a posição já está ocupada
        if (grid[row][col] == 'X' || grid[row][col] == 'O') 
        {
            printf("Position already taken! Try again.\n");
            continue;
        }

        if (isPlayer1Turn)
        {
            grid[row][col] = 'X'; 
        }
        else
        {
            grid[row][col] = 'O'; 
        }

        isPlayer1Turn = !isPlayer1Turn;
    }

    return 0;
}

void displayBoard()
{
    int rows = 3;
    int columns = 3;

    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("| %c  ", grid[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}