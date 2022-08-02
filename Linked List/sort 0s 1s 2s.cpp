// 1

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


Node *insertEnd(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL)return temp;
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return head;
    
}

void sortList(Node *head)
{
    int count[3] = {0, 0, 0}; 
    Node *ptr = head;
 
    while (ptr != NULL)
    {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }
 
    int i = 0;
    ptr = head;
 
    while (ptr != NULL)
    {
        if (count[i] == 0)
            ++i;
        else
        {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

int main() 
{ 
	Node *head=new Node(0);
	Node *temp1=new Node(1);
	Node *temp2=new Node(0);
	head->next=temp1;
	temp1->next=temp2;
    head=insertEnd(head,2);
    head=insertEnd(head,1);
    head=insertEnd(head,1);
    head=insertEnd(head,2);
    printlist(head);
    sortList(head);
    printlist(head);

	return 0;
} 

// 2

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


Node *insertEnd(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL)return temp;
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return head;
    
}

Node* sortList2(Node* head)
{
    if (!head || !(head->next))
        return head;
 
    Node* zeroD = new Node(0);
    Node* oneD = new Node(0);
    Node* twoD = new Node(0);
 

    Node* zero = zeroD, *one = oneD, *two = twoD;
 
    Node* curr = head;
    while (curr) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = zero->next;
            curr = curr->next;
        } else if (curr->data == 1) {
            one->next = curr;
            one = one->next;
            curr = curr->next;
        } else {
            two->next = curr;
            two = two->next;
            curr = curr->next;
        }
    }
 
    zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
    one->next = twoD->next;
    two->next = NULL;
 
    head = zeroD->next;
 
    delete zeroD;
    delete oneD;
    delete twoD;
 
    return head;
}

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

int main() 
{ 
	Node *head=new Node(0);
	Node *temp1=new Node(1);
	Node *temp2=new Node(0);
	head->next=temp1;
	temp1->next=temp2;
    head=insertEnd(head,2);
    head=insertEnd(head,1);
    head=insertEnd(head,1);
    head=insertEnd(head,2);
    printlist(head);
    head = sortList2(head);
    printlist(head);

	return 0;
} 