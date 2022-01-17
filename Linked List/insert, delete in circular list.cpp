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
    
    if(head==NULL)
    {
        n->next=n;
        head=n;
        return;
    }
    
    node* temp = head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next = n;
    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val)
{
    node* n= new node(val);
    
    if(head==NULL)  //no element in list initially
    {
        insertAtHead(head, val); 
        return;
    }
    
    node* temp = head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next = n;
    n->next=head;
}

void deleteAtHead(node* &head)
{
    node* temp = head;
    while(temp->next!=head)
    {
        temp=temp->next; 
    }
    node* todelete = head;
    temp->next=head->next;
    head=head->next;
    
    delete todelete;
}

void deletion(node* head, int val) //point val-1 th element next to val+1 th element next
{
    if(head==NULL)
    return;
    
    if(head->next==head)
    {
       deleteAtHead(head);
       return;
    }
    
    node* temp = head;
    while(temp->next->data!=val)
    {
        temp=temp->next; 
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    
    delete todelete;
}

void deletion2(node* head, int pos) //point val-1 th element next to val+1 th element next
{
    
    if(pos==1)
    {
       deleteAtHead(head);
       return;
    }
    
    node* temp = head;
    int c=1;
    while(c!=pos-1)
    {
        temp=temp->next; 
        c++;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    
    delete todelete;
}

void print(node* head)
{
     node* temp = head;
     
     do
     {
         cout<<temp->data<<" ";
         temp=temp->next;
     }while(temp!=head);
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
    
    insertAtHead(head, 4);
    print(head);
    
    deletion(head, 2);
    print(head);
    
    deletion(head, 3);
    print(head);
    
    deleteAtHead(head);
    print(head);
    
}