#include<stdio.h>
struct Node{
    int data;
    struct Node *next;

};

struct LinkList{
    Node *head;
    Node *tail;    
}

void createLinkList(LinkList &lst)
{
    lst.head = NULL;
    lst.tail = NULL;
}



struct Node{
    int data;
    struct Node *next;

};


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

int main()
{
    LinkList lst;
    createLinkList(lst);
    Node* newnode = createNode(3);
}