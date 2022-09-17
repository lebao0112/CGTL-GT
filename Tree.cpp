#include<bits/stdc++.h>

struct node
{
    int data;
    struct node* node_left;
    struct node* node_right;
};

typedef node* NODE;

NODE createNewnode(int data)
{
    NODE newnode = new node;
    newnode->data = data;
    newnode->node_right = NULL;
    newnode->node_left = NULL;

    return newnode;
}

void PreOrder(NODE root)
{
    if(root != NULL)
    {
        printf("%4d",root->data);
        PreOrder(root->node_left);
        PreOrder(root->node_right);
    }
}

void InOrder(NODE root)
{
    if(root != NULL)
    {
        InOrder(root->node_left);
        printf("%4d",root->data);
        InOrder(root->node_right);
    }
}

void PostOrder(NODE root)
{
    if(root != NULL)
    {
        PostOrder(root->node_left);
        PostOrder(root->node_right);
        printf("%4d",root->data);
    }
}

void InsertLeft(NODE n, int data)
{
    if(n == NULL)
    {
        printf("\nNode ko ton tai");
    }
    else 
        if(n->node_left != NULL){
            printf("\nNode da ton tai");
        }
        else
            n->node_left = createNewnode(data);
}

void InsertRight(NODE n, int data)
{
    if(n == NULL)
    {
        printf("\nNode ko ton tai");
    }
    else 
        if(n->node_right != NULL){
            printf("\nNode da ton tai");
        }
        else
            n->node_right = createNewnode(data);
}

void ClearTree(NODE &root)
{
    if(root != NULL)
    {
        ClearTree(root->node_left);
        ClearTree(root->node_right);
        delete root;
    }
}

NODE Search(NODE root, int x)
{
    NODE p;
    if(root->data == x)
    {
        return root;
    }
    if(root == NULL)
        return NULL;
    p = Search(root->node_left,x);
    if(p == NULL)
        p = Search(root->node_right,x);
    return p;
}



int main(){

    return 0;
}