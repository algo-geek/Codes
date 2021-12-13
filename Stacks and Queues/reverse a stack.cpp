#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int e)
{
    if(s.empty())
    {
        s.push(e);
        return;
    }
    
    int tope=s.top();
    s.pop();
    
    insertAtBottom(s, e);
    
    s.push(tope);
}

void reverse(stack<int> &s)
{
    if(s.empty())
    return;
    
    int e=s.top();
    s.pop();
    reverse(s);
    
    insertAtBottom(s, e);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    reverse(s);
    
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}