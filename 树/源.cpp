#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define ERROR 0
#define OK 1
using namespace std;
typedef struct BitNode
{
	char data;
	struct BitNode* lchild, * rchild;
}BiTNode,*Bitree;

typedef struct
{
	Bitree* base;
	Bitree* top;
	int stackmise;
}sqstack;

int initstack(sqstack& s)
{
	s.base = new Bitree[100];
	if (!s.base)
		return ERROR;
	s.top = s.base;
	s.stackmise = 100;
	return OK;
}

int push(sqstack& s, Bitree root)
{
	if (s.top - s.base == s.stackmise)
		return ERROR;
	*s.top++ = root;
	return OK;
}

int pop(sqstack& s, Bitree &Q)
{
	if (s.top == s.base)
		return ERROR;
	Q = *--s.top;
	return OK;
}

int stackempty(sqstack s)
{
	if (s.top == s.base)
		return true;
	else
		return false;
}
Bitree initbitree()
{
	Bitree root;
	char ch;
	cin >> ch;
	if ('#' == ch)
		root = NULL;
	else
	{
		root = new BiTNode;
		root->data = ch;
		root->lchild = initbitree();
		root->rchild = initbitree();
	}
	return root;
}
//void inordertraverse_1(Bitree T)
//{
//	if (T)
//	{
//		inordertraverse_1(T->lchild);
//		cout << T->data;
//		inordertraverse_1(T->rchild);
//	}
//}
void inordertraverse_2(Bitree T)
{
	sqstack s;
	initstack(s);
	Bitree Q = new BiTNode;
	Bitree root=T;

	while (root||!stackempty(s))
	{
		if (root)
		{
			push(s, root);
			root=root->lchild;
		}
		else
		{
			pop(s, Q);
			cout << Q->data;
			root = Q->rchild;
		}
	}
}
int main()
{
	Bitree T;
	T = initbitree();

	//inordertraverse_1(T);//中序递归遍历
	inordertraverse_2(T);//中序非递归遍历
	return 0;
}//-+a##*b##-c##d##/e##f##