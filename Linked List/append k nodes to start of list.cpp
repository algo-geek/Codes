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

int length(node* head)
{
    int l=0;
    node* temp=head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;
    }
    return l;
}

node* kappend(node* &head, int k)
{
    node* newhead;
    node* newtail;
    node* tail=head;
    
    int l=length(head);
    k=k%l;   //in case k is greater than l
    int c=1;
    
    while(tail->next!=NULL)
    {
        if(c==l-k)
        {
            newtail=tail;
        }
        if(c==l-k+1)
        {
            newhead=tail;
        }
        tail=tail->next;
        c++;
    }
    newtail->next=NULL;
    tail->next=head;
    
    return newhead;
}

int main()
{
    node*head=NULL;
    // insertAtTail(head, 1);
    // insertAtTail(head, 2);
    // insertAtTail(head, 3);
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
       insertAtTail(head, x);
    }
    
    node* newhead=kappend(head, 3);
    print(newhead);
}