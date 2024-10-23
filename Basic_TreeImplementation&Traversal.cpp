#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
    Node (int data)
    {
        this-> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};
typedef struct Node sn;
void preOrderTraverse( sn *node)
{
    if(node == NULL)
    {
        return;
    }
    cout << node-> data << " ";
    preOrderTraverse(node -> left);
    preOrderTraverse(node -> right);
}
void PostOrdertraverse(sn *node)
{
    if(node == NULL)
    return;
    PostOrdertraverse(node -> left);
    PostOrdertraverse(node -> right);
    cout << node->data << " ";
}
void inordertraverse( sn *node)
{
    if( node == NULL)
    {
        return;
    }
    inordertraverse(node ->left);
    cout<< node -> data <<" ";
    inordertraverse(node -> right);
}
int main()
{
    sn *root = new Node(1);
    root-> left = new Node(2);
    root-> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    preOrderTraverse(root);
    cout<<endl;
    PostOrdertraverse(root);
    cout<<endl;
    inordertraverse(root);
}