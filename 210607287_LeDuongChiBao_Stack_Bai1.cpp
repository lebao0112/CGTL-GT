#include<bits/stdc++.h>
#include<string.h>
#define MAX 100
struct node{
	int data;
	struct node* next;
};

typedef node* STACK;



void InitStack(STACK &stk)
{
	stk = NULL;
}

int isEmptyStack(STACK stk)
{
	return (stk == NULL);
}

node* creatNewStack(int data)
{
	node* newnode = new node; 
	newnode->data = data;
	newnode->next = NULL;
	
	return newnode; 
}

void Push(STACK &stk, int data)
{
	node* newnode = creatNewStack(data);
	if(isEmptyStack(stk))
	{
		stk = newnode;
	}
	else
	{
		newnode->next = stk;
		stk = newnode;
	}
}

void showStack(STACK stk)
{
	while(stk != NULL){
		printf("%d ",stk->data);
		stk = stk->next;
	}
}

void ConvertDecToBin(STACK &stk, int dec)
{
	int num1;
	while(dec > 0){
		num1 = dec % 2;
		Push(stk,num1);
		dec = dec / 2;
	}
}

void ChuyenTrungToSangHauTo(STACK &stk, char bt[])
{
	int i=0;
	int j=0
	char output[MAX];
	while(i < strlen(bt)){
		if(bt[i] >= '0' and bt[i] <= '9' )\
		{
			output[j++] = bt[i];
		}
		
	}
}


int main()
{
	STACK stk;
	InitStack(stk);
	int dec ;
	printf("\nNhap so thap phan: ");
	scanf("%d",&dec);
	ConvertDecToBin(stk,dec);
	printf("\nSo nhi phan sau khi chuyen doi: ");
	showStack(stk);
	

	return 0;
}
