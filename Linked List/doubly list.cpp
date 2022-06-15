
// basic
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
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
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
	printlist(head);
	return 0;
} 

// insert at head, tail
// delete at head, tail
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
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

Node *insertBegin(Node *head,int data){
    Node *temp=new Node(data);
    temp->next=head;
    
    if(head!=NULL)
    head->prev=temp;

    return temp;
    
}

Node *insertEnd(Node *head,int data){
    Node *temp=new Node(data);
    if(head==NULL)return temp;
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    return head;
}

Node *delHead(Node *head){
    if(head==NULL)return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }    
    else{
        Node *temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        return head;
    }
}

Node *delLast(Node *head){
    if(head==NULL)return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }    
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->prev->next=NULL;
    delete curr;
    return head;
    
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
	head=insertBegin(head,5);
	printlist(head);
    cout<<endl;
    head=insertEnd(head,40);
	printlist(head);
    cout<<endl;
    head=delHead(head);
	printlist(head);
    cout<<endl;
    head=delLast(head);
	printlist(head);
	return 0;
} 

