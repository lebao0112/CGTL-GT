#include<stdio.h>
#define MAXSTACK 100
#define MAX 100

struct node{
    int data;
    struct node* next;
};

typedef struct node* NODE;

typedef struct stack
{
    NODE top;
}Stack;

// khoi tao
void Init(Stack &s)
{
    s.top = NULL;
}

//kiem tra rong
bool isEmpty(stack s)
{
   return (s.top == NULL);
}


// int isFULL(Stack s){
//     return (s.top == MAXSTACK - 1);
// }

NODE InitNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;

    return temp;
}

void Push(Stack &s, NODE p)
{
    if(isEmpty(s))
    {
        s.top = p;
    }
    else{
        p->next = s.top;
        s.top = p; // cap nhat lai top
    }
}

void Pop(Stack &s)
{
    int x;
     if(isEmpty(s)){
        printf("\nStack is empty");
        return;
     }
     else{
        NODE temp = new node();
        temp = s.top;
        s.top = s.top->next; 
        x = temp->data; 
        delete temp;
     }
}

void ShowStack(Stack s)
{
    while(s.top != NULL)
    {
        printf("%d -> ",s.top->data);
        s.top = s.top->next;
    }
}

void ShowTop(Stack s)
{
    printf("%d",s.top->data);
}

int main()
{
    Stack s;
    NODE n1 = InitNode(1);
    Push(s,n1);
    NODE n2 = InitNode(2);
    Push(s,n2);
    NODE n3 = InitNode(3);
    Push(s,n3);

    Pop(s);
    ShowStack(s);
    // ShowStack(s);


}