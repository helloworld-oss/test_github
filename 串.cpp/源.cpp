#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define OK 1
#define ERROR 0
#define MAXLEN 255
using namespace std;

typedef struct
{
	char ch[MAXLEN + 1];
	int length;
}SString;

int Index_BF(SString S, SString T, int pos)
{
	int i = pos, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i-1] == T.ch[j-1])
			++i, ++j;
		else
			i = i - j + 2, j = 1;
	}
	if (j > T.length)
		return i - T.length;
	else
		return ERROR;
}
int main()
{
	SString S, T;
	int m = 0, n = 0, pos = 0;
	cin >> m >> n >> pos;
	S.length = T.length = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> S.ch[i];
		++S.length;
	}
	for (int j = 0; j < n; j++)
	{
		cin >> T.ch[j];
		++T.length;
	}
	Index_BF(S, T, pos);
	printf("%d ", Index_BF(S, T, pos));
	return 0;
}