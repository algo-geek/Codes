#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* pre;
    
    node(int val)// constructor
    {
        data=val;
        next=NULL;
        pre=NULL;
    }
};

void insertAtHead(node* &head, int val)
{
    node* n= new node(val);
    n->next=head;
    
    if(head!=NULL)// no node in list, we wont be able to access pre of node we add
    {
        head->pre=n;
    }
    
    head=n;
}


void insertAtTail(node* &head, int val)
{
    node* n= new node(val);
    
    if(head==NULL)//no element in list initially
    {
        insertAtHead(head, val);
        return;
    }
    
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = n;
    n->pre=temp;
}

void deleteAtHead(node* &head)
{
    node* todelete = head;
    head=head->next;
    head->pre=NULL;
    
    delete todelete;
}

void deletion(node* &head, int pos)
{
    
    if(pos==1)
    {
       deleteAtHead(head);
       return;
    }
    
    int c=1;
    node* temp = head;
    
    while(temp!=NULL && c!=pos)
    {
        temp=temp->next; 
        c++;
    }

    temp->pre->next=temp->next;
    
    if(temp->next!=NULL)
    {
        temp->next->pre=temp->pre;
    }
    
    delete temp;
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
    
    insertAtHead(head, 5);
    print(head);
    
    deletion(head, 1);
    print(head);
}