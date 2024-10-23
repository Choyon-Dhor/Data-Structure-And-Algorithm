#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *root = nullptr;
void add_node(int data)
{
    if(root == nullptr)
    {
        root = new Node;
        root->data = data;
        root->next = nullptr;
    }
    else
    {
        Node *current_node = root;
        while(current_node->next != nullptr)
        {
            current_node = current_node -> next;
        }
        Node *New_node = new Node;
        New_node->data = data;
        New_node ->next = nullptr;
        current_node ->next = New_node;
    }
}
void printList()
{
    Node *current_node = root;
    while (current_node != nullptr)
    {
        cout << current_node->data <<endl;
        current_node = current_node->next;
    }
    
}
void Delete_Node(int data)
{
    Node *current_node = root;
    Node *previous_node = nullptr;
    while (current_node->data != data)
    {
        previous_node = current_node;
        current_node = current_node ->next;
    }
    if(current_node == root)
    {
        Node *temp = root;
        root = root->next;
        delete(temp);
    }
    else
    {
        previous_node->next = current_node->next;
        delete(current_node);
    }

}
void forward(Node *node)
{
    if(node != nullptr)
    {
        cout << node->data <<" ";
        forward(node->next);
    }
    cout<<"\n";
}
int main()
{
    int arr[]={ 1 , 3, 6, 8, 10};
    for (int i = 0; i < 5; i++)
    {
        add_node(arr[i]);
    }
    printList();
    Delete_Node(6);
    cout<< "After deletion"<<endl;
    printList();
    forward(root);
}