#include<stdio.h>
#include<stdlib.h>

#define N 15
int chessboard[N + 1][N + 1] = {0};
int WhoseTurn = 0;


void PrintChessBoard()
{
    int i,j;
    for(i = 0;i < N+1;i++)
    {
        for(j = 0; j < N+1;j++)
        {
            if(i == 0)
                printf("%3d",j);        //column number
            else if(j == 0) 
                printf("%3d",i);        //row number 
            else if(chessboard[i][j] == 1)
                printf(" X");
            else if(chessboard[i][j] == 2)
                printf(" O");
            else 
                printf(" *");
        }
        printf("\n");
    }
}

void InitGame()
{
    char c;
    printf("*************\n   WELCOME   \n*************\nEnter y to start a new game!\n");
    c = getchar();
    if(c != 'Y' && c != 'y')
        exit(0);
    system("CLS");
    PrintChessBoard();
}

int judge(int x,int y)
{
    int i,j;
    int t = 2 - WhoseTurn % 2;
    const int step[4][2] = {{-1,0},{0,-1},{1,1},{1,0}};
    for(int i = 0;i < 4;i++)
    {
        int count = 1;
        const int dir[2] = {-1,1};  
        for(j = 0;j < 2;j++)
        {
            for(int k = 1;k <= 4;k++)
            {
                int row = x + k*dir[j] * step[i][0];
                int col = y + k*dir[j] * step[i][1];
                if(row >= 1 && row <= N && chessboard[x][y] == chessboard[row][col])
                    count++;
                else 
                    break;
            }
        }
        if(count >= 5)
            return 1;
    }
    return 0;
}

void PlayChess()
{
    int i,j,winner;
    if( WhoseTurn % 2)
    {
        printf("Player 1's turn,enter the coordinate(row,column) of chess piece(exp.1 2)");
        scanf("%d %d",&i,&j);
        chessboard[i][j] = 1;
    }
    else
    {
        printf("Player 2's turn,enter the coordinate(row,column) of chess piece(exp.1 2)");
        scanf("%d %d",&i,&j);
        chessboard[i][j] = 2;
    }
    system("CLS");
    PrintChessBoard();
    if(judge(i,j))
    {
        if(WhoseTurn % 2 == 1)
        {
            printf("Player 1 is the Winner\n");
            exit(0);
        }
        else
        {
            printf("Plaer2 is the winner\n");
            exit(0);
        }
    }
}

int main()
{
    InitGame();
    while(1)
    {
        WhoseTurn++;
        PlayChess();
    }

    return 0;
}
