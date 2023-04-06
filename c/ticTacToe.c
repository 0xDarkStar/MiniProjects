// This script will be a simple tic tac toe game.
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void drawBoard(char board[3][3]);

int main() {
    char board[3][3] = {
        {'x', 'o', 'x'}, 
        {'o', 'x', 'o'}, 
        {'x', 'o', 'x'}
    };
    printf("\033[0;2mThis is a simple tic tac toe game. Enjoy.\n");
    drawBoard(board);
    printf("Input the coordinates of where you want to start. (E.g. \"12\" for the top middle spot)");
    int choice[2];
    scanf("%i", &choice);
    int coordinate;
    
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
