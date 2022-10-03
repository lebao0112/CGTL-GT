#include<bits/stdc++.h>
#include<string.h>
#define MAX 100
struct node{
	char data;
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

node* creatNewStack(char data)
{
	node* newnode = new node; 
	newnode->data = data;
	newnode->next = NULL;
	
	return newnode; 
}

void Push(STACK &stk, char data)
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

char Pop(STACK &stk)
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
		printf("%c ",stk->data);
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
void infixtoPostfix(char infix[])
{
	char postfix[MAX];
	STACK stk;
	char x, token;
	int i = 0, j = 0;    // i-index of infix,j-index of postfix
	InitStack(stk);
	for (i = 0; infix[i] != '\0'; i++)
	{
		token = infix[i];
		if (isNum(token))
			postfix[j++] = token;
		else
			if (token == '(')
				Push(stk,token);
			else
			{
				if (token == ')')
				{
					while (x != '(')
					{	
						x = Pop(stk);
						postfix[j++] = x;
					}
		
				}
	
				else
				{
					while ( !isEmptyStack(stk) )//xet do uu tien cua toan tu
					{
						if(  douutien(token) <= douutien(stk->data))
						{
						x = Pop(stk);
						postfix[j++] = x;
						}
						else 
						 break;
					}
					Push(stk, token);
				}
			}
	}

	while (!isEmptyStack(stk))
	{
		x = Pop(stk);
		postfix[j++] = x;
	}

	postfix[j] = '\0';
	printf("%s",postfix);
}

int main()
{
	char infix[MAX];
	printf("\nNhap bieu thuc trung to: ");
	gets(infix);
	fflush(stdin);

	infixtoPostfix(infix);
	// STACK stk;
	// InitStack(stk);
	// Push(stk,'5');
	// Push(stk,'0');
	// Push(stk,'r');
	// showStack(stk);
	// char temp = stk->data;
	// printf("%d",douutien(stk->data));


	
	return 0;
}

