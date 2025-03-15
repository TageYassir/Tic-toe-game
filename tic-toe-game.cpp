#include <stdio.h>

char board[3][3];  


void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '.';
        }
    }
}


void dispBoard() {
	int i,j;
    printf("  1 2 3\n");
    for (i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
            printf("\n");
        if (i < 2) {
            printf("  -----\n");
        }
    }
    printf("\n");
}

int status() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!='.') {
            return 1;  
        }
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!='.') {
            return 1;  
        }
    }
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!='.') {
        return 1;   
    }
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!='.') {
        return 1;  
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j]=='.') {
                return 0;
            }
        }
    }

    return -1;
}
int main() {
    int row, col;
    char Player = 'X';

    initBoard();
    dispBoard();

    while (1) {
        printf("Player %c  enter your move (row (space) col): ",Player);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1]!='.') {
            printf("Invalid move.\n");
            continue;
        }

        board[row-1][col-1]=Player;
        dispBoard();

        int gameState = status();
        if (gameState==1) {
            printf("Player %c Marbouha!!!!!!!!!!!!!\n", Player);
            break;
        } else if (gameState == -1) {
            printf("It's Ta3adoul.\n");
            break;
        }
        Player=(Player=='X') ? 'O' : 'X';
    }

}

