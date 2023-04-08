// This script will be a simple tic tac toe game.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Made by 0xDarkStar

void drawBoard(char board[3][3]); // Draws the tic tac toe board
void conversion(char board[3][3]);
void winCheck(int boardInt, int who);
void CPU(char board[3][3]);

int main() {
    system("clear");
    char board[3][3] = {
        {' ', ' ', ' '}, 
        {' ', ' ', ' '}, 
        {' ', ' ', ' '}
    };
    printf("\033[0;2mThis is a simple tic tac toe game. Enjoy.\n");
    int a, i = 5;
    drawBoard(board);
    for (a = 0; a < i; a++) {
        printf("Input the coordinates of where you want to place your mark (E.g. \"21\" for the top middle spot)\n");
        int choice;
        scanf("%3i", &choice);
        choice = abs(choice);
        printf("%i\n", choice);
        int coordinate[2] = {0, 0};
        int i, moving;
        for (i = 0; i < 2; i++) {
            if (choice % 10 > 3) {
                choice /= 10;
                continue;
            }else {
                moving = choice % 10;
                coordinate[i] = moving;
                choice = choice / 10;
            }
            
        }
        int x, y;
        (coordinate[0] == 0) ? (y = coordinate[0]) : (y = coordinate[0]-1);
        (coordinate[1] == 0) ? (x = coordinate[1]) : (x = coordinate[1]-1);

        printf("(%i, %i)\n", x, y);
        if (board[y][x] == 'x' || board[y][x] == 'o') {
            i++;
        }
        board[y][x] = 'x';
        
        system("clear");
        CPU(board);
        drawBoard(board);
        conversion(board);
    }
    return 0;
}

void drawBoard(char board[3][3]) {
    /*
    All Unicode codes used:
        \u2502 --> thin vertical line
        \u2500 --> thin horizontal line
        \u253c --> thin vertical line and horizontal line (like a + but it reaches all edges) 
    */
    printf("    1    2    3\n");                                                                       // looks like that
    printf("1  %2c \u2502 %2c \u2502 %2c\n", board[0][0], board[0][1], board[0][2]);                   //    x | x  | x
    printf("  \u2500\u2500\u2500\u2500\u253c\u2500\u2500\u2500\u2500\u253c\u2500\u2500\u2500\u2500\n");//  ----+----+----
    printf("2  %2c \u2502 %2c \u2502 %2c\n", board[1][0], board[1][1], board[1][2]);                   //    x | x  | x
    printf("  \u2500\u2500\u2500\u2500\u253c\u2500\u2500\u2500\u2500\u253c\u2500\u2500\u2500\u2500\n");//  ----+----+----
    printf("3  %2c \u2502 %2c \u2502 %2c\n", board[2][0], board[2][1], board[2][2]);                   //    x | x  | x
}

void conversion(char board[3][3]) {
    int i, j; // making integers for nested loops
    int moveBoard[3][3] = { // board to then turn into an entire integer
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };
    for (i = 0; i < 3; i++) { // check each row
        for (j = 0; j < 3; j++) { // check each column
            if (board[i][j] == 'x') { // If there is an x in that slot
                moveBoard[i][j] = 1; // turn it into a 1
            }
        }
    }
    int boardInt = 0;
    for (i = 0; i < 3; i++) { // for each row
        for (j = 0; j < 3; j++) { // for each column
            boardInt *= 10; // multiply by 10 to be able to add 1 number to the end (right side)
            boardInt += moveBoard[i][j]; // add that number to the end (add a 2 or 1 to the right side)
        }
    }
    winCheck(boardInt, 0); // check
    int moveBoardCPU[3][3] = { // board to then turn into an entire integer
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };
    for (i = 0; i < 3; i++) { // check each row
        for (j = 0; j < 3; j++) { // check each column
            if (board[i][j] == 'o') { // If there is an x in that slot
                moveBoardCPU[i][j] = 1; // turn it into a 1
            }
        }
    }
    int boardIntCPU = 0;
    for (i = 0; i < 3; i++) { // for each row
        for (j = 0; j < 3; j++) { // for each column
            boardIntCPU *= 10; // multiply by 10 to be able to add 1 number to the end (right side)
            boardIntCPU += moveBoardCPU[i][j]; // add that number to the end (add a 2 or 1 to the right side)
        }
    }
    winCheck(boardIntCPU, 1); // check
}

void winCheck(int boardInt, int who) {
    char boardStr[10], winSequenceStr[10]; // string variables
    int i, j, winSeqNum, boardIntNum; // number variables
    int winList[] = {111222222, 222111222, 222222111, 122212221, 122122122, 212212212, 221221221, 221212122}; // list of win conditions
    int Trues = 0; // to keep track of the

    sprintf(boardStr, "%d", boardInt); // turn integer into string to get individual characters

    for (j = 0; j < 8; j++) { // to go through the list of win conditions
        sprintf(winSequenceStr, "%d", winList[j]); // turns sequence into a string to get individual characters
        for (i = 0; i < strlen(boardStr); i++) { // go through the string to get each character
            winSeqNum = winSequenceStr[i]; // turn the single character from the sequence into an integer
            boardIntNum = boardStr[i]; // turn the single character from the board layout into an integer
            switch (winSeqNum) { // check what the number is in the sequence
                case 49: // It's a 1, move to the next switch below
                    switch (boardIntNum) { // check what number is in the board layout
                        case 49: // It's a 1, it matches the sequence
                            Trues++; // add 1 to the Trues variable
                        case 50: // It's a 2, they don't match
                            continue; // Go to next loop
                    }
                case 50: // It's a 2, it doesn't matter what what is in the board layout
                    continue; // Go to next loop
            }
        }
        if (Trues == 3) { // It matches a sequence, they win
            switch(who) {
                case 0:
                    printf("You Win!\033[0;0m\n");
                    exit(1);
                case 1:
                    printf("You Lose!\033[0;0m\n");
                    exit(1);
            }
        }else { // it didn't match the sequence
            Trues = 0; // reset the Trues and go on to next loop (it ends if it's the final loop)
        }
    }
}

void CPU(char board[3][3]) {
    int i, j;
    int a = 0;
    int xList[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int yList[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 'x' || board[i][j] == 'o') {
                continue;
            }else if (board[i][j] == ' ') {
                xList[a] = j;
                yList[a] = i;
                a++;
            }
        }
    }
    int coordList[] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (i = 0; i < a; i++) {
        coordList[i] = i;
    }

    srand(time(NULL));  // Initialize the random number generator with the current time

    // Generate a random index from the list
    int randomIndex = rand() % a;
    int randomCoord = coordList[randomIndex];
    j = xList[randomCoord];
    i = yList[randomCoord];
    board[i][j] = 'o';
}
