//Tinh gia tri bieu thuc trung to
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

void xuly(STACK &stk, int ia, int ib, char p)
{
     if(p == '+')
        {
                 Push(stk,ib + ia + '0');
             } else if(p == '-')
             {
                 Push(stk,ib - ia + '0');
             } else if(p == '*')
              {
                 Push(stk,ib * ia + '0');
             } else if(p == '/')
              {
                 Push(stk,ib / ia + '0');
              } else if(p == '^')
              {
                  Push(stk,pow(ib,ia) + '0');
              }
}

int Calculate_Infix(char infix[]) // TInh gia tri bieu thuc trung to
{
    STACK stk1, stk2;
    InitStack(stk1);
    InitStack(stk2);
    char token, x;
    int ia,ib;
    char p;
    for(int i=0; infix[i] != '\0'; i++)
    {
        token = infix[i];
        if(isNum(token))
        {
            Push(stk1,token);
        }else if (token == '(')
        {
            Push(stk2,token);
        }else if (token == ')')
        {
            while(stk2->data != '(')
            {
                int  ia = Pop(stk1) - '0'; // chuyen so kieu char sang kieu int, vd: '9' -> 9
                int ib = Pop(stk1) - '0';
                char p = Pop(stk2);
                xuly(stk1,ia,ib,p);
            }
            Pop(stk2);
        }else 
        {
            	while ( !isEmptyStack(stk2) )//xet do uu tien cua toan tu
					{
						if(  douutien(token) <= douutien(stk2->data))
						{
					        int ia = Pop(stk1) - '0';
                            int ib = Pop(stk1) - '0';
                                p = Pop(stk2);
                               xuly(stk1,ia,ib,p);
						}   
                       
						else 
						 break;
					}
				Push(stk2, token);
        }
        
        
    }

    while(!isEmptyStack(stk2))
    {
        int  ia = Pop(stk1) - '0'; // chuyen so kieu char sang kieu int, vd: '9' -> 9
        int ib = Pop(stk1) - '0';
        p = Pop(stk2);
        xuly(stk1,ia,ib,p);
    }

    char kq = stk1->data;
    int ikq = kq - '0';
    return ikq;
}


int main()
{
    
	char infix[MAX];
	printf("\nNhap bieu thuc trung to: ");
	gets(infix);
	fflush(stdin);
    int a = Calculate_Infix(infix);
    printf("%d",a);
    return 0;
}