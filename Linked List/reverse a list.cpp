
#include <bits/stdc++.h>
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

// naive
node *revList(node *head)
{
    vector<int>a;
    for(node *curr=head;curr!=NULL;curr=curr->next)
    {
        a.push_back(curr->data);
    }
    for(node *curr=head;curr!=NULL;curr=curr->next)
    {
        curr->data=a.back();
        a.pop_back();
    }
    return head;
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

// tail recursive
node *recRevL(node *curr,node *prev){
    if(curr==NULL)return prev;
    node *next=curr->next;
    curr->next=prev;
    return recRevL(next,curr);
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
    
    node* newhead=revList(head);
    print(newhead);
    cout<<endl;
    node* newhead=reverse(head);
    print(newhead);
    cout<<endl;
    node* newhead=reverse2(head);
    print(newhead);
    node* newhead=recRevL(head, NULL);
    print(newhead);
}

