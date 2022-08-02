// using stack // O(n) time & space
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

// Function to check if the linked list
// is palindrome or not
bool isPalin(Node* head)
{
		Node* slow= head;
		stack <int> s;
		while(slow != NULL)
        {
				s.push(slow->data);
				slow = slow->next;
		}

		while(head != NULL )
        {		
			int i=s.top();
			s.pop();

			if(head -> data != i)
            {
				return false;
			}

		head=head->next;
		}

return true;
}

int main(){

	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3); 
    head->next->next->next = new Node(2); 
    head->next->next->next->next = new Node(1); 

	
	int result = isPalin(head);

	if(result == 1)
			cout<<"isPalindrome is true\n";
	else
		cout<<"isPalindrome is false\n";

return 0;
}

// reverse half and compare with other half // O(n) time and O(1) space
#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    char data;
    Node* next;
    Node(char x){
        data=x;
        next=NULL;
    }
};

Node *reverseList(Node *head){
    if(head==NULL||head->next==NULL)
    return head;
    
    Node *rest_head=reverseList(head->next);
    Node *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}

bool isPalindrome(Node *head){
        if(head==NULL)return true;
        Node *slow=head,*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *rev=reverseList(slow->next);
        Node *curr=head;
        while(rev!=NULL){
            if(rev->data!=curr->data)
                return false;
            rev=rev->next;
            curr=curr->next;
        }
        return true;
    }


int main() 
{ 
	Node *head=new Node('g');
	head->next=new Node('f');
	head->next->next=new Node('g');
	if(isPalindrome(head))
	    cout<<"Yes";
	else
	    cout<<"No";
	return 0;
} 


