
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

// 1
void insertAtHead(node* &head, int val)
{
    node* n= new node(val); 
    n->next=head;
    head=n;
}

// 2
// Node *insertBegin(Node *head,int x){
//     Node *temp=new Node(x);
//     temp->next=head;
//     return temp;
    
// }

// 1
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

// 2
// Node *insertEnd(Node *head,int x){
//     Node *temp=new Node(x);
//     if(head==NULL)return temp;
//     Node *curr=head;
//     while(curr->next!=NULL){
//         curr=curr->next;
//     }
//     curr->next=temp;
//     return head;
    
// }

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

bool search(node* head, int key)
{
    node* temp = head;
    while(temp!=NULL)
     {
         if(temp->data==key)
         {
             return true;
         }
         temp=temp->next;
     }
     return false;
}

// 1
void deleteAtHead(node* &head)
{
    node* todelete = head;
    head=head->next;
    
    delete todelete;
}

// 2
// Node *delHead(Node *head){
//     if(head==NULL)
//          return NULL;
//     else
//      {
//         Node *temp=head->next;
//         delete(head);
//         return temp;
//     }
// }

void deletion(node* head, int val)//point val-1 th element next to val+1 th element next
{
    if(head==NULL)
    return;
    
    if(head->next==NULL)
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

int main()
{
    node*head=NULL;
    // 1
    // insertAtTail(head, 1);
    // insertAtTail(head, 2);
    // insertAtTail(head, 3);

    // 2
    // head=insertBegin(head,30);
	// head=insertBegin(head,20);
	// head=insertBegin(head,10);

    // delete 2-->
	// head=delHead(head);
	// printlist(head);

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
    
    cout<<search(head, 3)<<endl;
    
    // deletion(head, 3);
    deleteAtHead(head);
    print(head);
}

