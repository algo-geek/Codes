#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int d){
        data=d;
        prev=NULL;
        next=NULL;
    }
};

void printlist(Node *head){
    if(head==NULL)return;
    Node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}

// insert at head
Node *insertBegin(Node *head, int x)
{
    Node *temp=new Node(x);

    if(head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        return temp;
    }
    else
    {
        temp->prev=head->prev;
        temp->next=head;
        head->prev->next=temp;
        head->prev=temp;

        return temp;
    }
}

// insert at tail
Node *insertEnd(Node *head, int x)
{
    Node *temp=new Node(x);

    if(head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        return temp;
    }
    else
    {
        temp->prev=head->prev;
        temp->next=head;
        head->prev->next=temp;
        head->prev=temp;

        return head;
    }
}

int main() 
{ 
	Node *head=new Node(10);
	Node *temp1=new Node(20);
	Node *temp2=new Node(30);
	head->next=temp1;
	temp1->prev=head;
	temp1->next=temp2;
	temp2->prev=temp1;
    temp2->next=head;
    head->prev=temp2;
	head=insertBegin(head,5);
	printlist(head);
    cout<<endl;
    head=insertEnd(head,40);
	printlist(head);
}