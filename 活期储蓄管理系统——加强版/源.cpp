#include"Bank.h"

Bank* InitList()
{
	Bank* q;
	q = (Bank*)malloc(sizeof(Bank));
	q->next = NULL;
	q->length = 0;
	return q;
}//初始化

bool LandAccount(Account* a, Bank* L, int* i)
{
	printf("请登陆你的账户\n");
	Account* s = L->next;
	printf("请输入储户姓名：");
	scanf("%s", a->name);
	printf("请输入密码：");
	scanf("%s", a->password);
	for (*i = 0; (*i) < L->length; (*i)++)
	{
		if (!strcmp(a->name, s->name) && !strcmp(a->password, s->password))
		{
			printf("登陆成功\n");
			return true;
		}
	}//遍历账户信息，查看是否登陆成功
	printf("你的账户或密码有误\n");
	return false;
}//登陆账户，成功返回true，失败返回false

void OpenAccount(Bank* L)
{
	Account* a, * s;
	s = L->next;
	a = (Account*)malloc(sizeof(Account));
	printf("请输入储户姓名：");
	scanf("%s", a->name);
	for (int i = 0; i < L->length; i++)
	{
		if (!strcmp(a->name, s->name))
		{
			printf("账户已存在\n");
			exit(-1);
		}//判断开户者是否已经有账户
		s = s->next;
	}
	printf("请输入你的密码：");
	scanf("%s", a->password);
	sprintf(a->cardID, "%d", rand() % 100000000);//获取一个随机的卡号
	printf("请输入你的账户余额：");
	scanf("%lf", &a->balance);
	a->next = L->next;
	L->next = a;
	L->length++;//将创建的账户插入到L链表;
	printf("开户成功\n");
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
		}//循环找到需要删除的账户
		printf("是否确定销户\n");
		printf("0.取消  1.确定\n");
		int m = 0;
		cin >> m;
		if (m)
		{
			s->next = s->next->next;
			L->length--;
			printf("账户删除成功\n");
		}//删除匹配的账户
		else
		{
			printf("账户删除失败\n");
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
		}//找到需要存款的账户
		printf("请输入你需要存款的金额\n");
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
		}//找到需要取款的账户
		printf("请输入你需要取款的金额\n");
		int balence2 = 0;
		cin >> balence2;
		s->next->balance -= balence2;
	}
}