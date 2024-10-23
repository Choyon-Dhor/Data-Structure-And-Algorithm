#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next, *prev;
};
Node *root = nullptr;
void insertion(int index, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = nullptr;
    if(index == 0)
    {
        if(root == nullptr)
        {
            root = new_node;
        }
        else
        {
            new_node->next = root;
            root->prev = new_node;
        }
    }
    else
    {
        Node *temp = root;
        for (int i = 0; i < index-1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if(temp == nullptr)
        {
            cout<<"Index out of bound"<<endl;
            delete new_node;
            return;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
    }
}
void print(Node *node)
{
    if(node != nullptr)
    {
        cout << node->data <<" ";
        print(node->next);
    }
}
int main()
{
    int arr[] = {1, 2, 4, 8, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        insertion(i,arr[i]);
    }
    print(root);
    cout<<"\n";
    cout<<"After insertion: ";
    insertion(3,6);
    print(root);
    return 0;
}
