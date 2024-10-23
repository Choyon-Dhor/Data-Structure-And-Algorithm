#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node *root, *tail;
void add_node(int data)
{
    if(root == nullptr)
    {
        root = new Node;
        root->data = data;
        root->next = nullptr;
        tail = root;
    }
    else
    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;
        tail->next = new_node;
        tail = new_node;
    }
}

void insertion(int index, int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    if(index == 0)
    {
        new_node->next = root;
        root = new_node;
    }
    else
    {
        Node *current = root;
        for(int i = 0; i < index - 1 && current!= nullptr; i++)
        {
            current = current->next;
        }
        if(current == nullptr)
        {
            cout << "Index out of bounds" << endl;
            delete(new_node);
            return;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}
void printList()
{
    Node *current_node = root;
    while (current_node != nullptr)
    {
        cout << current_node->data <<" ";
        current_node = current_node->next;
    }
    cout<<"\n";
}
void forward(Node *node)
{
    if(node != nullptr)
    {
        cout << node->data <<" ";
        forward(node->next);
    }
}
void backward(Node *node)
{
    if(node != nullptr)
    {
        backward(node->next);
        cout << node->data <<" ";
    }
}
int length()
{
    Node *current = new Node;
    current = root;
    int count = 0;
    while(current != nullptr)
    {
        count ++;
        current = current->next;
    }
    return count;
}
int main()
{
    int arr[] = {1, 2, 4, 8, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        add_node(arr[i]);
    }
    printList();
    insertion(4,5);
    cout<<"After insertion Traverse Forward: " <<endl;
    forward(root);
    cout<<"\n";
    cout<<"Backward traversal: ";
    backward(root);
    cout<<"\n";
    cout<<"Length of List: "<<length()<<endl;

    return 0;
}