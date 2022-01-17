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

void intersect(node* head1, node* head2, int pos)// to intersect two list
{
    node* temp1=head1;
    while(pos--)
    {
        temp1=temp1->next;
    }
    
    node* temp2=head2;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
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

int intersection(node* head1, node* head2)
{
    int l1=length(head1);
    int l2=length(head2);
    
    int d=0;
    node* p1;
    node* p2;
    
    if(l1>l2)
    {
        d=l1-l2;
        p1=head1;
        p2=head2;
    }
    else
    {
        d=l2-l1;
        p1=head2;
        p2=head1;
    }
    
    while(d--)// to traverse d distance of longer list
    {
        p1=p1->next;
        if(p1==NULL)// no intersection point
        {
            return -1;
        }
    }
    
    while(p1!=NULL && p2!=NULL)
    {
        if(p1==p2)
        {
            return p1->data;
        }
        p1=p1->next;
        p2=p2->next;
    }
    return -1;
}

int main()
{
    node*head1=NULL;
    node* head2=NULL;

    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
       insertAtTail(head1, x);
    }
    
    int m;
    cin>>m;
    
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
       insertAtTail(head2, x);
    }
    
    intersect(head1, head2, 3);
    print(head1);
    print(head2);
    cout<<intersection(head1, head2)<<endl;
}