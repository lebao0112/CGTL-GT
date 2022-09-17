#include<bits/stdc++.h>

struct node
{
    int data;
    struct node* node_left;
    struct node* node_right;
};

typedef node* NODE;
typedef NODE TREE;

NODE createNewnode(int data)
{
    NODE newnode = new node;
    newnode->data = data;
    newnode->node_right = NULL;
    newnode->node_left = NULL;

    return newnode;
}

void InitTree(TREE &root)
{
    root = NULL;
}

int isEmpty(TREE root)
{
    return (root == NULL);
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

void AddNode(TREE &root, NODE newnode)
{
    if (root)
    {
        if (root->data == newnode->data) // Nếu bị trùng giá trị thì không thêm
            return;
        if (newnode->data < root->data) // Thêm vào cây con bên trái (nhỏ hơn nút hiện tại)
            AddNode(root->node_left, newnode);
        else
            AddNode(root->node_right, newnode); // Thêm vào cây con bên phải (lớn hơn nút hiện tại)
    }
    else
    {
        root = newnode; // Đã tìm thấy vị trí thích hợp, thêm node vào
    }
}

//Tim kiem 
NODE FindNode(TREE root, int x)
{
    if(root){
           if(root->data == x)
                return root;
            if(x < root->data)
                return FindNode(root->node_left,x);
            return FindNode(root->node_right,x);

    }
    return NULL; // khong tim thay
}



int main(){
    TREE root;
    InitTree(root);
    NODE n1 = createNewnode(1);
    NODE n2 = createNewnode(3);
    NODE n3 = createNewnode(5);
    NODE n4 = createNewnode(10);
    AddNode(root,n1);
    AddNode(root,n2);
    AddNode(root,n3);
    AddNode(root,n4);

    PreOrder(root);

    return 0;
}