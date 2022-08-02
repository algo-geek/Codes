
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

int countPairs(struct Node* first, struct Node* second, int value)
{
    int count = 0;
    while (first != NULL && second != NULL && first != second && second->next != first) 
    {
         if ((first->data + second->data) == value) 
        {
            count++;
 
            first = first->next;
            second = second->prev;
        }

        else if ((first->data + second->data) > value)
            second = second->prev;
        else
            first = first->next;
    }
 
    return count;
}
 

int countTriplets(struct Node* head, int x)
{
    if (head == NULL)
        return 0;
 
    Node* current, *first, *last;
    int count = 0;

    last = head;
    while (last->next != NULL)
        last = last->next;
 
    for (current = head; current != NULL; current = current->next) 
    {
        first = current->next;
        count += countPairs(first, last, x - current->data);
    }
 
    return count;
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
	int x = 17;
 
    cout<<countTriplets(head, x);
    

	return 0;
} 