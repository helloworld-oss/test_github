#define _CRT_SECURE_NO_WARNINGS

#include"game.h"


void menu()
{
	printf("********************************\n");
	printf("*******    1.play    ***********\n");
	printf("*******    0.exit    ***********\n");
	printf("********************************\n");
}

void game()
{
	//存储数据——二维数组
	char board[ROW][COL];
	char ret = 0;

	//初始化棋盘——初始化空格
	InitBoard(board, ROW, COL);

	//打印棋盘——本质上是打印数组
	DisplayBoard(board, ROW, COL);
	
	//玩家和电脑走
	while (1)
	{
		//玩家下棋
		PlayMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否获胜
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("玩家获胜\n");
	}
	else if (ret == '#')
	{
		printf("电脑获胜\n");
	}
	else
	{
		printf("平局\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新输入\n");
		}
	} while (input);
	return 0;
}