#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int m = 1;
void Move(char a, int n, char c)
{
	printf("%d.第%d号圆盘由%c移动到%c\n", m++, n, a, c);
}
void hanoi(char a,char b,char c,int n)
{
	if (n == 1)
	{
		Move(a, 1, c);
	}
	else
	{
		hanoi(a, c, b, n-1);
		Move(a, n, c);
		hanoi(b, a, c, n - 1);
	}
}

int main()
{
	char a = 'A', b = 'B', c = 'C';
	int n = 0;
	scanf("%d", &n);
	hanoi(a, b, c, n);
	return 0;
}