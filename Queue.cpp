#include<bits/stdc++.h>
#define MAX 100

typedef struct queue{
    int front;
    int Array[MAX];
    int rear;
    int count;
}Queue;

typedef int item;

void InitQueue(Queue &Q){
    Q.front = 0;
    Q.rear = -1;
    Q.count = 0;
}

bool isEmpty(Queue Q)
{
    return (Q.count == 0);
}

bool isFull(Queue Q)
{
    return (Q.count == MAX);
}

void Push(Queue &Q, item x)
{
    if(isFull(Q)){
        printf("\nThe queue is full");
    }
    else{
        Q.Array[++Q.rear] = x;
        Q.count++;
    }
}

int Pop(Queue &Q)
{
    item x;
    if(isEmpty(Q)){
        printf("The queue is empty, can not pop \n");
    }else{
        x = Q.Array[Q.front];
        for(int i = Q.front; i <= Q.rear; i++)
            Q.Array[i] = Q.Array[i+1];
        Q.rear--;
        Q.count--;
        return x;
    }
}

void ShowQueue(Queue Q)
{
    for(int i = Q.front; i < Q.rear; i++)
        printf("%d -> ",Q.Array[i]);
}

int main(){
    Queue Q;
    Push(Q,3);
    Push(Q,3);
    Push(Q,3);
    ShowQueue(Q);
    
}