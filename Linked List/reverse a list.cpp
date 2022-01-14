
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

node* reverse(node* &head)// iterative method
{
    node* pre=NULL;
    node* cur=head;
    node* next;
    
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=pre;
        
        pre=cur;
        cur=next;
    }
    return pre;
}

node* reverse2(node* &head)// recursive method
{
    if(head==NULL || head->next==NULL)// base case when list is blank or has only 1 node
    return head;
    
    node* newhead = reverse2(head->next);// recursive function
    
    head->next->next = head;
    head->next=NULL;
    
    return newhead;
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
    
    // node* newhead=reverse(head);
    // print(newhead);
    
    node* newhead=reverse2(head);
    print(newhead);
}

