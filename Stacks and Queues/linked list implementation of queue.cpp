#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int val)// constructor
    {
        data=val;
        next=NULL;
    }
};

class queue{

    node* front;
    node* back;
    
    public:
    
    queue()
    {
        front=NULL;
        back=NULL;
    }
    
    void push(int x)
    {
        node* n=new node(x);
        
        if(front==NULL)// if queue is empty
        {
            front=n;
            back=n;
            return;
        }
        back->next=n;
        back=n;
    }
    
    void pop()
    {
        if(front==NULL)
        {
            cout<<"no element to pop"<<endl;
            return;
        }
        node* todelete=front;
        front=front->next;
        
        delete todelete;
    }
    
    int peek()
    {
        if(front==NULL)
        {
            cout<<"no element in queue"<<endl;
        }
        
        return front->data;
    }
    
    bool empty()
    {
        return (front==NULL);
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