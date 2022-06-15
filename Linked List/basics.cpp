// creation
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

int main() 
{ 
	Node *head=new Node(10);
	// Node *temp1=new Node(20);
	// Node *temp2=new Node(30);
	// head->next=temp1;
	// temp1->next=temp2;
    // cout<<head->data<<"-->"<<temp1->data<<"-->"<<temp2->data;
    head->next=new Node(20);
    head->next->next=new Node(30);
	cout<<head->data<<"-->"<<head->next->data<<"-->"<<head->next->next->data;
	return 0;
} 

// traversal
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

// recursive // time: O(n) // space: O(n)
void rPrint(Node *head)
{
    if(head==NULL)
    return;

    cout<<head->data<<" ";
    rPrint(head->next);
}

// iterative // time: O(n) // space: O(1)
void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	printlist(head);
    rPrint(head);
	return 0;
} 

