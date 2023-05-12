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
	//�洢���ݡ�����ά����
	char board[ROW][COL];
	char ret = 0;

	//��ʼ�����̡�����ʼ���ո�
	InitBoard(board, ROW, COL);

	//��ӡ���̡����������Ǵ�ӡ����
	DisplayBoard(board, ROW, COL);
	
	//��Һ͵�����
	while (1)
	{
		//�������
		PlayMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ����Ϸ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ��ʤ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("��һ�ʤ\n");
	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������\n");
		}
	} while (input);
	return 0;
}