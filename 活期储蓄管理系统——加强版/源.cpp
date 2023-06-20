#include"Bank.h"

Bank* InitList()
{
	Bank* q;
	q = (Bank*)malloc(sizeof(Bank));
	q->next = NULL;
	q->length = 0;
	return q;
}//��ʼ��

bool LandAccount(Account* a, Bank* L, int* i)
{
	printf("���½����˻�\n");
	Account* s = L->next;
	printf("�����봢��������");
	scanf("%s", a->name);
	printf("���������룺");
	scanf("%s", a->password);
	for (*i = 0; (*i) < L->length; (*i)++)
	{
		if (!strcmp(a->name, s->name) && !strcmp(a->password, s->password))
		{
			printf("��½�ɹ�\n");
			return true;
		}
	}//�����˻���Ϣ���鿴�Ƿ��½�ɹ�
	printf("����˻�����������\n");
	return false;
}//��½�˻����ɹ�����true��ʧ�ܷ���false

void OpenAccount(Bank* L)
{
	Account* a, * s;
	s = L->next;
	a = (Account*)malloc(sizeof(Account));
	printf("�����봢��������");
	scanf("%s", a->name);
	for (int i = 0; i < L->length; i++)
	{
		if (!strcmp(a->name, s->name))
		{
			printf("�˻��Ѵ���\n");
			exit(-1);
		}//�жϿ������Ƿ��Ѿ����˻�
		s = s->next;
	}
	printf("������������룺");
	scanf("%s", a->password);
	sprintf(a->cardID, "%d", rand() % 100000000);//��ȡһ������Ŀ���
	printf("����������˻���");
	scanf("%lf", &a->balance);
	a->next = L->next;
	L->next = a;
	L->length++;//���������˻����뵽L����;
	printf("�����ɹ�\n");
}

void DeleteAccount(Bank* L)
{
	Account* a;
	Bank* s;
	int i = 0;
	a = (Account*)malloc(sizeof(Account));
	s = L;
	if (LandAccount(a, L, &i))
	{
		for (int j = 1; j < i; j++)
		{
			s->next = s->next->next;
		}//ѭ���ҵ���Ҫɾ�����˻�
		printf("�Ƿ�ȷ������\n");
		printf("0.ȡ��  1.ȷ��\n");
		int m = 0;
		cin >> m;
		if (m)
		{
			s->next = s->next->next;
			L->length--;
			printf("�˻�ɾ���ɹ�\n");
		}//ɾ��ƥ����˻�
		else
		{
			printf("�˻�ɾ��ʧ��\n");
		}
	}
}

void DepositAccount(Bank* L)
{
	Account* a;
	Bank* s = L;
	int i = 0;
	a = (Account*)malloc(sizeof(Account));
	if (LandAccount(a, L, &i))
	{
		for (int j = 1; j < i; j++)
		{
			s->next = s->next->next;
		}//�ҵ���Ҫ�����˻�
		printf("����������Ҫ���Ľ��\n");
		int balence1 = 0;
		cin >> balence1;
		s->next->balance += balence1;
	}
}

void WithdrawAccount(Bank* L)
{
	Account* a;
	Bank* s = L;
	int i = 0;
	a = (Account*)malloc(sizeof(Account));
	if (LandAccount(a, L, &i))
	{
		for (int j = 1; j < i; j++)
		{
			s->next = s->next->next;
		}//�ҵ���Ҫȡ����˻�
		printf("����������Ҫȡ��Ľ��\n");
		int balence2 = 0;
		cin >> balence2;
		s->next->balance -= balence2;
	}
}