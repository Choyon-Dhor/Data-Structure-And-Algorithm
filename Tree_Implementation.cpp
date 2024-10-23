#include <bits/stdc++.h>
using namespace std;
struct Node 
{
    int data;
    Node *left;
    Node *right;
    Node (int data)
    {
        this-> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

typedef Node sn;

sn* buildTree(sn* node)
{
    cout<< "Enter Data: "<< endl;
    int data;
    cin >> data;
    node = new Node(data);
    if( data == -1)
    return NULL;
    cout<< "Enter Left data: "<< node->data <<endl;
    node-> left = buildTree(node->left);
    cout<< "Enter Right data: "<< node-> data << endl;
    node->right = buildTree(node->right);
    return node;
}
void BuildTree_levelOrder(sn* &root)
{
    queue<sn*> q;
    int data;
    cout<< "Enter Data: "<< endl;
    cin>>data;
    root = new Node(data);
    q.push(root);
    while(!q.empty())
    {
        sn *temp = q.front();
        q.pop();
        cout<< "Enter Left data: "<< temp->data << endl;
        int dataL;
        cin>>dataL;
        if(dataL== -1)
        {
            temp->left = NULL;
        }
        else
        {
            temp ->left = new Node(dataL);
            q.push(temp -> left);
        }
        cout<< "Enter right data: "<< temp->data << endl;
        int dataR;
        cin>>dataR;
        if(dataL== -1)
        {
            temp->right = NULL;
        }
        else
        {
            temp ->right = new Node(dataR);
            q.push(temp -> right);
        }
    }

}
void LevelOrderTraverse(sn *node)
{
    if(node == NULL)
    return;
    cout<< "Level Order Traversal: "<< endl;
    queue<sn*> q;
    q.push(node);
    q.push(NULL);
    while(!q.empty())
    {
        sn *temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout<< endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else 
        {
            cout<< temp->data << " ";
            if(temp->left != NULL)
            q.push(temp -> left);
            if( temp -> right)
            q.push( temp -> right);
        }
    }
}

int main()
{
    sn* root = NULL;
    //root = buildTree(root);
    BuildTree_levelOrder(root);
    LevelOrderTraverse(root);
    return 0;
}
//1 2 4 -1 -1 5 -1 -1 3 -1 -1 