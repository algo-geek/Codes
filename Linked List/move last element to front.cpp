
// 1
#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
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

Node *order(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    Node *curr=head;
    
    while(curr->next->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next->next=head;
    head=curr->next;
    curr->next=NULL;
    
    return head;
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	printlist(head);
	head=order(head);
	printlist(head);
	return 0;
} 

// 2
#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
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

void order2(Node* &head)
{
    if(head==NULL || head->next==NULL)
    return;
    
    Node *curr=head;
    
    while(curr->next->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next->next=head;
    head=curr->next;
    curr->next=NULL;
    
    // return head;
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	printlist(head);
	order2(head);
	printlist(head);
	return 0;
} 