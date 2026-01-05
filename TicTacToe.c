#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void displayBoard();

int main()
{
    bool isPlayer1Turn = true;
    bool checkVictory = false;
    int numTurns = 0;

    while (!checkVictory && numTurns != 9)
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
        int row = (choiceNum - 1) / 3; 
        int col = (choiceNum - 1) % 3; 

        if (grid[row][col] == 'X' || grid[row][col] == 'O')
        {
            printf("Position already taken! Try again.\n");
            continue;
        }

        numTurns++;

        if (isPlayer1Turn)
        {
            grid[row][col] = 'X';
        }
        else
        {
            grid[row][col] = 'O';
        }

        isPlayer1Turn = !isPlayer1Turn;

        // Bloco de Verificação de Vitória
        {
            bool row1 = (grid[0][0] == grid[0][1]) && (grid[0][1] == grid[0][2]);
            bool row2 = (grid[1][0] == grid[1][1]) && (grid[1][1] == grid[1][2]);
            bool row3 = (grid[2][0] == grid[2][1]) && (grid[2][1] == grid[2][2]);
            bool col1 = (grid[0][0] == grid[1][0]) && (grid[1][0] == grid[2][0]);
            bool col2 = (grid[0][1] == grid[1][1]) && (grid[1][1] == grid[2][1]);
            bool col3 = (grid[0][2] == grid[1][2]) && (grid[1][2] == grid[2][2]);
            bool diag1 = (grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2]);
            bool diag2 = (grid[0][2] == grid[1][1]) && (grid[1][1] == grid[2][0]);
            
            checkVictory = row1 || row2 || row3 || col1 || col2 || col3 || diag1 || diag2;

            if (checkVictory)
            {
                displayBoard();
                if (!isPlayer1Turn) 
                {
                    printf("Player 1 (X) wins!\n");
                }
                else
                {
                    printf("Player 2 (O) wins!\n");
                }
                break;
            }
        }

        if (numTurns == 9 && !checkVictory)
        {
            displayBoard();
            printf("Tie!\n");
        }
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