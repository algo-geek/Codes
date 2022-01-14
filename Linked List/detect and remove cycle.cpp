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

void insertAtTail(node* &head, int val)
{
    node* n= new node(val);
    
    if(head==NULL)//no element in list initially
    {
        head=n;
        return;
    }
    
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = n;
}

void print(node* head)
{
     node* temp = head;
     while(temp!=NULL)
     {
         cout<<temp->data<<" ";
         temp=temp->next;
     }
     cout<<endl;
}

void makeCycle(node* &head, int pos)
{
    node* temp=head;
    node* cycle;
    
    int c=1;
    while(temp->next!=NULL)
    {
        if(c==pos)
        cycle=temp;
        
        temp=temp->next;
        c++;
    }
    temp->next=cycle;
}

bool detectCycle(node* &head)
{
    node* slow=head;
    node* fast=head;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        
        if(fast==slow)
        return true;
    }
    return false;
}

void removeCycle(node* &head)// assuming that we have detected a cycle 
{
    node* slow=head;
    node* fast=head;
    
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    
    fast=head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

int main()
{
    int n;
    cin>>n;
    
    node* head=NULL;
    
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        insertAtTail(head, x);
    }
    makeCycle(head, 3);
    cout<<detectCycle(head)<<endl;
    
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    print(head);
}