#include <iostream>
using namespace std;

#define n 100

class queue{
    
    int* a;
    int front;
    int back;
    
    public:
    
    queue()
    {
        a=new int[n];
        front=-1;
        back=-1;
    }
    
    void push(int x)
    {
        if(back==n-1)
        {
            cout<<"queue overflow"<<endl;
            return;
        }
        back++;
        a[back]=x;
        
        if(front==-1)
        front++;
    }
    
    void pop()
    {
        if(front==-1 || front>back)
        {
            cout<<"no element to pop"<<endl;
            return;
        }
        front++;
    }
    
    int peek()
    {
        if(front==-1 || front>back)
        {
            cout<<"no element in queue"<<endl;
            return -1;
        }
        
        return a[front];
    }
    
    bool empty()
    {
        return (front==-1 || front>back);
    }
};

int main()
{
    queue s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    cout<<s.peek()<<endl;
    s.pop();
    
    cout<<s.peek()<<endl;
    s.pop();
    
    cout<<s.peek()<<endl;
    s.pop();

    cout<<s.empty()<<endl;
    
     s.pop();
    
    cout<<s.peek()<<endl;
}