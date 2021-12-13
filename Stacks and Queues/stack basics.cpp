#include <iostream>
using namespace std;

#define n 100

class stack{
    
    int* a;
    int top;
    
    public:
    
    stack()
    {
        a=new int[n];
        top=-1;
    }
    
    void push(int x)
    {
        if(top==n-1)
        {
            cout<<"stack overflow"<<endl;
            return;
        }
        top++;
        a[top]=x;
    }
    
    void pop()
    {
        if(top==-1)
        {
            cout<<"no element to pop"<<endl;
            return;
        }
        top--;
    }
    
    int Top()
    {
        if(top==-1)
        {
            cout<<"no element in stack"<<endl;
            return -1;
        }
        
        return a[top];
    }
    
    bool empty()
    {
        return (top==-1);
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.Top()<<endl;
    s.pop();
    cout<<s.Top()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.empty()<<endl;
}