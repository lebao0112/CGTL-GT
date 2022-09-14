struct Queue{
    int front, rear;
    int node[MAX];
}

void Init(Queue &q){
    q.front = 0;
    q.rear = -1;
}