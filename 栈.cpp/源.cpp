#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef struct
{
	int* base;
	int* top;
	int stacksize;
}sqstack;

int initstack(sqstack& l)
{
	l.base = new int[MAXSIZE];
	if (!l.base)
		exit(OVERFLOW);
	l.top = l.base;
	l.stacksize = MAXSIZE;
	return OK;
}

int push(sqstack& l, int e)
{
	if (l.base - l.top == l.stacksize)
		return ERROR;
	*l.top++ = e;
	return OK;
}

int pop(sqstack& l,int &e)
{
	if (l.base == l.top)
		return ERROR;
	e = *--l.top;
	return OK;
}
int main()
{
	sqstack l;
	initstack(l);

	int n = 0;
	cin >> n;
	while (n)
	{
		push(l, n % 8);
		n /= 8;
	}

	int e = 0;
	while (l.top - l.base)
	{
		pop(l, e);
		printf("%d", e);
	}
	return 0;
}