#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int val)
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

// method 1
// time: O(max(m, n)) // space: O(1)
Node* reverse(Node* &head)
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

Node *addUtil(Node *head1, Node *head2) 
{ 
    Node *a=head1, *b=head2, *temp=NULL, *res=a;
  
    int carry = 0, sum; 
  
    while (a && b)
    { 
        sum = carry + a->data + b->data; 
        carry = sum/10; 
        sum = sum % 10; 
  
        a->data = sum; 
  
        temp = a; 
        a = a->next;
        b = b->next;
    } 
    
    if (a || b) 
    {
 
        if (b)
            temp->next = b;
 
        a = temp->next;
 
        // While first list has digits remaining
        while (a) 
        {
            sum = a->data + carry;
            a->data = sum % 10;
            carry = sum / 10;
            temp = a;
            a = a->next;
        }
    }
  
    if (carry > 0) 
        temp->next = new Node(carry); 
  
    return res; 
} 
  
Node* add(Node *head1, Node *head2) 
{ 
    head1 = reverse(head1); 
    head2 = reverse(head2);
    
    Node *r = addUtil(head1, head2); 
    return reverse(r); 
} 
 

int main()
{
    Node *head1 = new Node(5); 
    head1->next = new Node(6); 
    head1->next->next = new Node(3); 
  
    Node *head2 = new Node(8); 
    head2->next = new Node(4); 
    head2->next->next = new Node(2); 
  
    Node *head = add(head1, head2); 
  
    cout << "Resultant list is "; 
    print(head); 
    
}