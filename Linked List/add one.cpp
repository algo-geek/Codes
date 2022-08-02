// iterative

#include <bits/stdc++.h>
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


Node* reverse(Node* &head)// iterative method
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
    return pre;
}

Node *addOneUtil(Node *head) 
{ 
    // res is head node of the resultant list 
    Node* res = head; 
    Node *temp; 
  
    int carry = 1, sum; 
  
    while (head != NULL) //while both lists exist 
    { 
        sum = carry + head->data; 
        carry = (sum >= 10)? 1 : 0; 
        sum = sum % 10; 
  
        // Create a new node with sum as data 
        head->data = sum; 
  
        // Move head and second pointers to next nodes 
        temp = head; 
        head = head->next; 
    } 
  
    // if some carry is still there, add a new node to 
    // result list. 
    if (carry > 0) 
        temp->next = new Node(carry); 
  
    // return head of the resultant list 
    return res; 
} 
  
Node* addOne(Node *head) 
{ 
    // reverse list
    head = reverse(head); 
    // add one
    head = addOneUtil(head); 
    // reverse result list
    return reverse(head); 
} 
 

int main()
{
    Node *head = new Node(1); 
    head->next = new Node(9); 
    head->next->next = new Node(9); 
    head->next->next->next = new Node(9); 
  
    cout << "List is "; 
    print(head); 
  
    head = addOne(head); 
  
    cout << "Resultant list is "; 
    print(head); 
    
}

// recursive

#include <bits/stdc++.h>
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


Node* reverse(Node* &head)// iterative method
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
    return pre;
}

int addWithCarry(Node* head)
{
    // If linked list is empty, then
    // return carry
    if (head == NULL)
        return 1;
  
    // Add carry returned be next node call
    int res = head->data + addWithCarry(head->next);
  
    // Update data and return new carry
    head->data = (res) % 10;
    return (res) / 10;
}
  
// This function mainly uses addWithCarry().
Node* addOne(Node* head)
{
    // Add 1 to linked list from end to beginning
    int carry = addWithCarry(head);
  
    // If there is carry after processing all nodes,
    // then we need to add a new node to linked list
    if (carry) {
        Node* newNode=new Node(carry);
        newNode->next = head;
        return newNode; // New node becomes head now
    }
  
    return head;
}
 

int main()
{
    Node *head = new Node(1); 
    head->next = new Node(9); 
    head->next->next = new Node(9); 
    head->next->next->next = new Node(9); 
  
    cout << "List is "; 
    print(head); 
  
    head = addOne(head); 
  
    cout << "Resultant list is "; 
    print(head); 
    
}

