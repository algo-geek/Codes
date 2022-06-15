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

void insertAtHead(node* &head, int val)
{
    node* n= new node(val);
    n->next=head;
    head=n;
}

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

void evenodd(node* &head)
{
    node* odd=head;
    node* even=head->next;
    node* evenstart=even;
    
    while(odd->next!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    
    // if(odd->next!=NULL)
    // {
    //     even->next=NULL;
    // }
    
    odd->next=evenstart;
    
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

int main()
{
    node*head=NULL;

    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        insertAtTail(head, x);
    }
    print(head);
    
    evenodd(head);
    print(head);
}