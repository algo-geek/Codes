#include<bits/stdc++.h>
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

void reverse2(Node* &head)// iterative method
{
    Node* pre=NULL;
    Node* cur=head;
    Node* next;
    
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=pre;
        
        pre=cur;
        cur=next;
    }
   head=pre;
}

void print(Node* head)
{
     Node* temp = head;
     while(temp!=NULL)
     {
         cout<<temp->data<<" ";
         temp=temp->next;
     }
     cout<<endl;
}


void _delLesserNodes(Node* &head)
{
    Node* current = head;
    Node* maxnode = head;
    Node* temp;
 
    while (current != NULL &&
           current->next != NULL)
    {
        if (current->next->data < maxnode->data)
        {
            temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else
        {
            current = current->next;
            maxnode = current;
        }
    }
}
 
void delLesserNodes(Node* &head)
{
    reverse2(head);
    _delLesserNodes(head);
    reverse2(head);
}
 

int main(){

	Node *head = new Node(12);
	head->next = new Node(15);
	head->next->next = new Node(10); 
    head->next->next->next = new Node(11); 
    head->next->next->next->next = new Node(5); 
    head->next->next->next->next->next = new Node(6); 
    head->next->next->next->next->next->next = new Node(2); 
    head->next->next->next->next->next->next->next = new Node(3); 

    print(head);
	delLesserNodes(head);
	cout << "Modified Linked List \n" ;
    print(head);
	

return 0;
}