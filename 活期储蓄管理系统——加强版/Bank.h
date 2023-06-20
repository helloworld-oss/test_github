#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

typedef struct Account
{
	char name[20] = { 0 };
	char cardID[20] = { 0 };
	char password[20] = { 0 };
	double balance = 0;
	struct Account* next;
}Account;//�˻�
typedef struct
{
	int length;
	Account* next;
}Bank;//����

Bank* InitList();
//��ʼ��
bool LandAccount(Account* a, Bank* L, int* i);
//�˻���¼
void OpenAccount(Bank* L);
//����
void DeleteAccount(Bank* L);
//����
void DepositAccount(Bank* L);
//���
void WithdrawAccount(Bank* L);
//ȡ��