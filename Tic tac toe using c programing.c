#include <stdio.h>
#include <stdlib.h>

void printInputMatrix();
void printBoard();
int addMark();
int check();

char board[3][3] = {' ',' ',' ',
                    ' ',' ',' ',
                    ' ',' ',' '};
int turn = 1; //1-Player 1 | 0-Player 2
char mark = 'O'; //O-Player 1 | X-Player 2
int input;

int main(){
    int won = 0;
    int validInput = 0;

    for(int i=0; i<9; i++){
        system("cls");
        printBoard();
        if(turn) printf("Player 1 Turn (Symbol: O)\n");
        else printf("Player 2 Turn (Symbol: X)\n");
        printInputMatrix();
        printf("Enter Input from Input Matrix: ");
        scanf("%d", &input);
        while(input<0 || input>9){
            printf("Invalid Input. Please Re-Enter input: ");
            scanf("%d", &input);
        }
        if(turn) mark = 'O';
        else mark = 'X';

        validInput = addMark();
        if( !validInput ){
            i--;
            continue;
        }
        won = check();
        if( won){
            system("cls");
            printBoard();
            if(turn) printf("\n*** Player 1 - You Won ***");
            else printf("\n*** Player 2 - You Won ***");
            break;
        }
        if(i==8){
            system("cls");
            printBoard();
            printf("\n*** MATCH DRAW ***");
        }

        turn = !turn;
    }

    return 0;
}

void printInputMatrix(){
    printf("\n\nINPUT MATRIX\n");
    printf(" 1 | 2 | 3 \n");
    printf("------------\n");
    printf(" 4 | 5 | 6 \n");
    printf("------------\n");
    printf(" 7 | 8 | 9 \n");
}

void printBoard(){
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("------------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("------------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int addMark(){
    for(int i=0,k=1; i<3; i++ ){
        for(int j=0; j<3; j++,k++){
            if( k==input )
                if(board[i][j] == ' '){
                    board[i][j] = mark;
                    return 1;
                }
                else{
                    printf("Invalid Input");
                    return 0;
                }
        }
    }
    return 0; // Added return statement to handle all code paths
}

int check(){
    //checking rows
    if(board[0][0]==mark && board[0][1]==mark && board[0][2]==mark)
        return 1;
    if(board[1][0]==mark && board[1][1]==mark && board[1][2]==mark)
        return 1;
    if(board[2][0]==mark && board[2][1]==mark && board[2][2]==mark)
        return 1;
    //checking Columns
    if(board[0][0]==mark && board[1][0]==mark && board[2][0]==mark)
        return 1;
    if(board[0][1]==mark && board[1][1]==mark && board[2][1]==mark)
        return 1;
    if(board[0][2]==mark && board[1][2]==mark && board[2][2]==mark)
        return 1;

    //checking diagonals
    if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark)
        return 1;
    if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark)
        return 1;

    return 0;
}
