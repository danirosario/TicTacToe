#include <stdio.h> // input/output library
#include <stdlib.h> // standard library
#include <stdbool.h> // boolean type library
#include <string.h> // string manipulation library

char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void displayBoard();
bool checkVictory();

int main()
{
    bool isPlayer1Turn = true;
    int numTurns = 0;

    while (numTurns < 9)
{
    system("cls");  //limpa a tela
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

    if (choice < '1' || choice > '9') {
        printf("Invalid choice. Please choose a number between 1 and 9.\n");
        system("pause");
        continue; 
    }

    int choiceNum = choice - '0';
    int row = (choiceNum - 1) / 3; // Calculate row index
    int col = (choiceNum - 1) % 3; // Calculate column index

    if (grid[row][col] == 'X' || grid[row][col] == 'O') {
        printf("Position already taken! Try again.\n");
        system("pause");
        continue;
    }

    grid[row][col] = isPlayer1Turn ? 'X' : 'O';
    numTurns++;

    if (checkVictory()) 
    {
        displayBoard();
        printf("Player %d (%c) wins!\n", isPlayer1Turn ? 1 : 2, grid[row][col]);
        return 0; 
    }

    if (numTurns == 9)
    {
        displayBoard();
        printf("Tie!\n");
        break;
    }

    isPlayer1Turn = !isPlayer1Turn;
}

    return 0;
}

bool checkVictory()
{
    for (int i = 0; i < 3; i++)
    {
        if ((grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) ||
            (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]))
        {
            return true;
        }
    }
    if ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) ||
        (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]))
    {
        return true;
    }
    return false;
}

void displayBoard()
{
    int rows = 3;
    int columns = 3;

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