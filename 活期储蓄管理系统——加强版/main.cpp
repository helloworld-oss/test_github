#include"Bank.h"

int main()
{
	Bank* L;
	L = InitList();
	int i = 1;
	while (i)
	{
		printf("����һ�������Խ������в�����\n");
		printf("-----------------------\n");
		printf("0.�˳� 1.���� 2.����\n3.��� 4.ȡ��\n");
		printf("-----------------------\n");
		printf("��ѡ����Ҫ���еĲ�����\n");
		cin >> i;//ͨ����ȡ�û�����������ж���Ҫ���еĲ���
		switch (i)
		{
		case 0:
			printf("�˳�\n");
			break;
		case 1:
			OpenAccount(L);
			break;//����
		case 2:
			DeleteAccount(L);
			break;//����
		case 3:
			DepositAccount(L);
			break;//���
		case 4:
			WithdrawAccount(L);
			break;//ȡ��
		}
	}
}