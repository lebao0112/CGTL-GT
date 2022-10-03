//Tinh gia tri bieu thuc trung to
#include<bits/stdc++.h>
#include<string.h>
#include<stdlib.h>
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

int Pop(STACK &stk)
{
	if(isEmptyStack(stk))
		return ' ';
	else
	{
		node* temp = new node;
		temp = stk;
		stk = stk->next;
		
		return temp->data;
	}
	
}

void showStack(STACK stk)
{
	while(stk != NULL){
		printf("%d ",stk->data);
		stk = stk->next;
	}
}

int isNum(char x)
{
	return (x <= '9' && x >= '0');
}

int douutien(char x)
{
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1 ;
	if (x == '*' || x == '/' || x == '%')
		return 2;

	return 3;
}

void xuly(STACK &stk, int ia, int ib, char p)
{
     if(p == '+')
        {
                 Push(stk,ia + ib);
             } else if(p == '-')
             {
                 Push(stk,ia - ib);
             } else if(p == '*')
              {
                 Push(stk,ia * ib);
             } else if(p == '/')
              {
                 Push(stk,ia / ib);
              } else if(p == '^')
              {
                  Push(stk,pow(ib,ia));
              }
}

int Calculate_Prefix(char prefix[]) // TInh gia tri bieu thuc trung to
{
    STACK stk;
    InitStack(stk);
    char token;
    for(int i = strlen(prefix)-1; i>=0; i--)
    {
        token = prefix[i];
        if(isNum(token))
        {

            Push(stk,token - '0');
        }else 
        {
            int a = Pop(stk);
            int b = Pop(stk);
            xuly(stk,a,b,token);
        }
        
    }

    int kq = stk->data;
    return kq;
}


int main()
{
    
	char prefix[MAX];
	printf("\nNhap bieu thuc tien to: ");
	gets(prefix);
	fflush(stdin);
    int a = Calculate_Prefix(prefix);
    printf("%d",a);
    // char a = '4';
    // int ia = a - '0';
    // printf("%d",ia);
    return 0;
}