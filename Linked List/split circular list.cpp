

#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

void printList(Node *head){
    if(head==NULL)return;
    Node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}


void splitList(Node *head, Node **head1, Node **head2)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;
     
    if(head == NULL)
        return;
     
    while(fast_ptr->next != head && fast_ptr->next->next != head)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
     
// if even nodes
    if(fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;
         
    *head1 = head;
         
    if(head->next != head)
        *head2 = slow_ptr->next;
         
         // make 2nd half circular
    fast_ptr->next = slow_ptr->next;
         
          // make 1st half circular
    slow_ptr->next = head;
}

int main() 
{ 
	Node *head=new Node(11);
	head->next=new Node(20);
	head->next->next=new Node(56);
	head->next->next->next=new Node(30);
	head->next->next->next->next=head;

    Node *head1=NULL;
    Node *head2=NULL;
    
    cout << "Original Circular Linked List ";
    printList(head);    
     
    splitList(head, &head1, &head2);
     
    cout << "\nFirst Circular Linked List ";
    printList(head1);
     
    cout << "\nSecond Circular Linked List ";
    printList(head2);

	return 0;
} 
