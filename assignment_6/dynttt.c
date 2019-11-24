/*
Srikar Valluri
CS 133C
Assignment 6

Tic Tac Toe!
*/
#include <stdio.h>
#include <stdbool.h>

struct board{
    char board[3][3];
    bool O;
    bool X;
    bool done;
};

struct board* setupBoard(){
    struct board *board, act_board;
    board = &act_board;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board->board[i][j] = '.';
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return board;
}

void printBoard(struct board* board){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

struct board* checkConditions(struct board* board){
    for(int i = 0; i < 3; i++){
        if(board->board[i][0] == 'O' && board->board[i][1] == 'O' && board->board[i][2] == 'O'){
            board->done = true;
            board->O = true;
        }
        if(board->board[i][0] == 'X' && board->board[i][0] == 'X' && board->board[i][2] == 'X'){
            board->done = true;
            board->X = true;
        }
    }
    for(int j = 0; j < 3; j++){
        if(board->board[0][j] == 'O' && board->board[1][j] == 'O' && board->board[2][j] == 'O'){
            board->done = true;
            board->O = true;
        }
        if(board->board[0][j] == 'X' && board->board[1][j] == 'X' && board->board[2][j] == 'X'){
            board->done = true;
            board->X = true;
        }
    }
    if(board->board[0][0] == 'O' && board->board[1][1] == 'O' && board->board[2][2] == 'O'){
        board->done = true;
        board->O = true;
    }
    if(board->board[0][2] == 'O' && board->board[1][1] == 'O' && board->board[2][0] == 'O'){
        board->done = true;
        board->O = true;
    }
    if(board->board[0][0] == 'X' && board->board[1][1] == 'X' && board->board[2][2] == 'X'){
        board->done = true;
        board->X = true;
    }
    if(board->board[0][2] == 'X' && board->board[1][1] == 'X' && board->board[2][0] == 'X'){
        board->done = true;
        board->X = true;
    }
    return board;
}



struct board* turnCycle(struct board* board){
    int i, j = 0;
    printf("Player 1, enter the x-coordinate for the 'O' character: ");
    scanf("%d", &i);
    printf("Player 1, enter the y-coordinate for the 'O' character: ");
    scanf("%d", &j);
    board->board[j][i] = 'O';
    printBoard(board);
    board = checkConditions(board);
    if(board->done == false){
        printf("Great!\n\n");
        printf("Player 2, enter the x-coordinate for the 'X' character: ");
        scanf("%d", &i);
        printf("Player 2, enter the y-coordinate for the 'X' character: ");
        scanf("%d", &j);
        board->board[j][i] = 'X';
        printBoard(board);
        board = checkConditions(board);
    }
    return board;
}

int main(){
    printf("Welcome to TicTacToe! Here's the Board: \n\n");

    struct board* board = setupBoard();
    board->done = false;
    board->O = false;
    board->X = false;

    int i = 0;
    while(board->done == false && i < 9){
        board = turnCycle(board);
        i++;
    }
    if(board->O == true){
        printf("Player 1 Wins!\n");
    }
    else if(board->X == true){
        printf("Player 2 Wins!\n");
    }
    else{
        printf("It's a TIE!");
    }
    return 0;
}