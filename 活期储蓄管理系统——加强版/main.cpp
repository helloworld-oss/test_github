#include"Bank.h"

int main()
{
	Bank* L;
	L = InitList();
	int i = 1;
	while (i)
	{
		printf("输入一个数字以进行下列操作：\n");
		printf("-----------------------\n");
		printf("0.退出 1.开户 2.销户\n3.存款 4.取款\n");
		printf("-----------------------\n");
		printf("请选择你要进行的操作：\n");
		cin >> i;//通过获取用户输入的数字判断其要进行的操作
		switch (i)
		{
		case 0:
			printf("退出\n");
			break;
		case 1:
			OpenAccount(L);
			break;//开户
		case 2:
			DeleteAccount(L);
			break;//销户
		case 3:
			DepositAccount(L);
			break;//存款
		case 4:
			WithdrawAccount(L);
			break;//取款
		}
	}
}