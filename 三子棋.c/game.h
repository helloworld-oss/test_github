
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

//函数的声明

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘的函数
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断结局
//玩家获胜‘*’
//电脑获胜‘#’
//平局    ‘Q’
//游戏继续‘C’
char IsWin(char board[ROW][COL], int row, int col);