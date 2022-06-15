// single list
// time: theta(position)
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int val)// constructor
    {
        data=val;
        next=NULL;
    }
};

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

Node *insert(Node *head, int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    return temp;
    
    if(x<head->data)
    {
        temp->next=head;
        return temp;
    }
    
    Node *curr=head;
    while(curr->next!=NULL && curr->next->data<x)
    {
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

int main()
{
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	printlist(head);
	head=insert(head, 35);
	printlist(head);
}


// doubly list
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    
    DoublyLinkedListNode* n= new DoublyLinkedListNode(data);
    DoublyLinkedListNode* temp = head;
    
    if(temp==NULL)//no element in list initially
    {
        head = n;
    }
   else if(temp->data > data){
        n->next = temp;
        temp->prev = n;
        head = n;
    }
    else{
        while((temp->next!=NULL)&&(temp->next->data < data)){
             temp=temp->next;
        }
        n->prev = temp;
        if (temp->next!=NULL){
            n->next = temp->next;
            temp->next->prev = n;
        }
        temp->next = n;
    }
    
    return head;
}