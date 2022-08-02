// to get common elements in two sorted lists
// time: O(m+n) 
// space: O(min(m, n))--output list can have min(n, m) nodes
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

// iterative
Node* sortedIntersect(Node *a, Node *b)
{
    Node *dummy=new Node(0);
    Node* tail = dummy;
    dummy->next = NULL;
 
    while (a != NULL && b != NULL) 
    {
        if (a->data == b->data) 
        {
            tail->next=a;
            tail = tail->next;
            a = a->next;
            b = b->next;
        }
        /* advance the smaller list */
        else if (a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }
    return (dummy->next);
}

// recursive // space: O(max(m,n))
Node* sortedIntersect2(Node* a, Node* b)
{
    if (a == NULL || b == NULL)
        return NULL;
 
    if (a->data < b->data)
        return sortedIntersect2(a->next, b);
 
    if (a->data > b->data)
        return sortedIntersect2(a, b->next);

    // when a->data == b->data
    Node* temp = new Node(a->data);
    // temp->data = a->data;
 
    temp->next = sortedIntersect2(a->next, b->next);
    return temp;
}


int main() 
{ 
	Node *head1=new Node(1);
	head1->next=new Node(2);
	head1->next->next=new Node(3);
	head1->next->next->next=new Node(4);
	head1->next->next->next->next=new Node(5);
	head1->next->next->next->next->next=new Node(6);
	printlist(head1);
	
	Node *head2=new Node(2);
	head2->next=new Node(4);
	head2->next->next=new Node(6);
	head2->next->next->next=new Node(8);
	printlist(head2);
	
	Node *intersect=NULL;
	intersect = sortedIntersect(head1, head2);
    cout<<"Linked list containing common items of a & b \n";
    printlist(intersect);

    Node *intersect2=NULL;
    intersect2 = sortedIntersect2(head1, head2);
    cout<<"Linked list containing common items of a & b \n";
    printlist(intersect2);
} 
