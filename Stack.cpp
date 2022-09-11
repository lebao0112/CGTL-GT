#include<bits/stdc++.h>
#define MAXSTACK 100
#define MAX 100
struct stack{
    int top;
    int nodes[MAXSTACK];
};
typedef struct stack Stack;


int isFULL(Stack s){
    return (s.top == MAXSTACK - 1);
}

struct Queue{
    int front, rear;
    int node[MAX];
}

void Init(Queue &q){
    q.front = 0;
    q.rear = -1;
}

int main()
{

}