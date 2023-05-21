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
}Account;//账户
typedef struct
{
	int length;
	Account* next;
}Bank;//银行

Bank* InitList();
//初始化
bool LandAccount(Account* a, Bank* L, int* i);
//账户登录
void OpenAccount(Bank* L);
//开户
void DeleteAccount(Bank* L);
//销户
void DepositAccount(Bank* L);
//存款
void WithdrawAccount(Bank* L);
//取款