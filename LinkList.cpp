#include<stdio.h>
struct Node{
    int data;
    struct Node *next;

};

struct LinkList{
    Node *head;
    Node *tail;    
};

void createLinkList(LinkList &lst)
{
    lst.head = NULL;
    lst.tail = NULL;
}


Node* createNode(int x){
    Node* newnode = new Node;
    newnode->data = x;
    newnode->next = NULL;

    return newnode;
}

Node* createHead(Node* newnode)
{
    newnode->data = NULL;
    newnode->next = NULL;
    return newnode;
}

bool isEmpty(LinkList lst)
{
    return (lst.head == NULL && lst.tail == NULL);
}

void insertFirst(LinkList &lst, Node *newnode)
{
    if(isEmpty(lst))
    {
        lst.head = newnode;
        lst.tail = newnode;
    }
}

void Input(LinkList &lst)
{
    int n;
    printf("\nNhap so luong phan tu: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){

    }
}

void DeleteAfter(Node *p)
{
    Node *q;
    if(p == NULL || p->next == NULL)
    {
        printf("\nCant delete node");
    }
    else{
        q = p->next;
        p->next = q->next;
        delete q;
    }
}

void ClearList(Node *phead)
{
    Node *tmp;
    while(phead != NULL)
    {
        tmp = phead;
        phead = phead->next;
        delete tmp;
    }
}

Node* TimNode(Node *phead, int i)
{
    Node *p = phead;
    int vitri = 0;
    while(p != NULL && vitri < i)
    {
        p = p->next;
        vitri++;
    }

    return p;
}

int Position(Node* phead, Node* p)
{
    int vitri = 0;
    Node* tmp = phead;
    while(tmp != NULL && tmp != p)
    {
        tmp = tmp->next;
        vitri++;
    }

    if(tmp == NULL)
        return -1;
    return vitri;
}


// Node* PreNode(Node* phead, Node* p)
// {
//     Node *q;
//     if()
// }

int main()
{
    LinkList lst;
    createLinkList(lst);
    Node* newnode = createNode(3);
}