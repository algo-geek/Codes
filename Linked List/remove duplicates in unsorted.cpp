// O(n^2)
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

void printList(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

void removeDuplicates(Node* head)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = head;
 
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
 
        while (ptr2->next != NULL) 
        {
            if (ptr1->data == ptr2->next->data) 
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

int main() 
{ 
	Node* head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(11);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(12);
    head->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->next = new Node(10);
 
    printf("Linked list before removing duplicates ");
    printList(head);
 
    removeDuplicates(head);
 
    printf("\nLinked list after removing duplicates ");
    printList(head);
} 

// O(n) time & space
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

void printList(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

void removeDuplicates(Node* head)
{
    unordered_set<int> s;
 
    Node* curr = head;
    Node* prev = NULL;
    while (curr != NULL) 
    {
        if (s.find(curr->data) != s.end()) 
        {
            prev->next = curr->next;
            delete (curr);
        }
        else 
        {
            s.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

int main() 
{ 
	Node* head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(11);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(12);
    head->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->next = new Node(10);
 
    printf("Linked list before removing duplicates ");
    printList(head);
 
    removeDuplicates(head);
 
    printf("\nLinked list after removing duplicates ");
    printList(head);
} 