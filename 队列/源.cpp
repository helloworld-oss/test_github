#include<stdio.h>
#include<iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

typedef struct
{
	char* base;
	int front;
	int rear;
}sqQueue;

int initQueue(sqQueue& Q)
{
	Q.base = new char[MAXSIZE];
	if (!Q.base) 
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

int enQueue(sqQueue& Q, char e)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}

int deQueue(sqQueue& Q, char& e)
{
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}
int main()
{
	sqQueue Q;
	initQueue(Q);

	int n = 0;
	char e;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> e;
		enQueue(Q, e);
	}
	while (deQueue(Q, e))
	{
		cout << e;
	}
	return 0;
}