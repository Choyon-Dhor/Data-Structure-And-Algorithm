#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); i++);
const int MX_size = 10;
struct Stack
{
    int top;
    int elements[MX_size];
};

typedef struct Stack st;

void createStack( st *s)
{
    s->top = -1;
}
bool isFull(st *s)
{
    if(s->top == MX_size -1 )
        return true;
    else
        return false;
}
bool isEmpty( st *s)
{
    if(s->top == -1)
        return true;
    else
        return false;
}
bool Push(st *s, int element)
{
    if(isFull(s))
    {
        cout << "Stack Overflow" << endl;
        return false;
    }
    else
    {
        s->elements[++s->top] = element;
        cout << element << " is added in the stack!" << endl;
        return true;
    }
}
void Pop( st *s)
{
    if(isEmpty(s))
    cout<<"Stack Underflow"<<endl;
    else
    {
        cout<<s->elements[s->top]<<" is POPED from the stack!"<<endl;
        s->top--;
    }
}
int TOP(st *s)
{
    if(isEmpty(s))
    {
        cout << "Stack is empty. Cannot retrieve top element." << endl;
        return -1; // or any other special value to indicate error
    }
    else 
    {
        return s->elements[s->top];
    }
}
int main()
{
    st s;
    createStack(&s);
    int arr[] = { 2, 4, 7, 10, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    f(i,0,n)
    {
        Push(&s,arr[i]);
    }
    cout<<"Top value is: "<<TOP(&s)<<endl;
    Pop(&s);
    cout<<"Top value is: "<<TOP(&s)<<endl;

    return 0;
}