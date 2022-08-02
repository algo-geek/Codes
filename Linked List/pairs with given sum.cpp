
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

void pairSum(struct Node *head, int x)
{
    Node *first = head;
    Node *second = head;
    while (second->next != NULL)
        second = second->next;
 
    bool found = false;

    while (first != second && second->next != first)
    {
        if ((first->data + second->data) == x)
        {
            found = true;
            cout << "(" << first->data<< ", " << second->data << ")" << endl;
 
            first = first->next;
             second = second->prev;
        }
        else
        {
            if ((first->data + second->data) < x)
                first = first->next;
            else
                second = second->prev;
        }
    }
 
    // if pair is not present
    if (found == false)
        cout << "No pair found";
}

int main() 
{ 
	Node *head=new Node(1);
	Node *temp1=new Node(2);
	Node *temp2=new Node(4);
	head->next=temp1;
	temp1->prev=head;
	temp1->next=temp2;
	temp2->prev=temp1;
    head=insertEnd(head,5);
    head=insertEnd(head,6);
    head=insertEnd(head,8);
    head=insertEnd(head,9);
	int x = 7;
 
    pairSum(head, x);
    

	return 0;
} 