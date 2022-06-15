// basic
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

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(5);
	head->next->next=new Node(20);
	head->next->next->next=new Node(15);
	head->next->next->next->next=head;
	return 0;
} 


// print
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

// 1
void printlist(Node *head){
    if(head==NULL)return;
    cout<<head->data<<" ";
    for(Node *p=head->next;p!=head;p=p->next)
        cout<<p->data<<" ";
}

// 2
void printlist(Node *head){
    if(head==NULL)return;
    Node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}


int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(5);
	head->next->next=new Node(20);
	head->next->next->next=new Node(15);
	head->next->next->next->next=head;
	printlist(head);
	return 0;
} 

// insert at head

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

void printlist(Node *head){
    if(head==NULL)return;
    Node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}

// insert at head naive
Node *insertBegin(Node * head,int x){
    Node *temp=new Node(x);
    if(head==NULL)
        temp->next=temp;
    else{
        Node *curr=head;
        while(curr->next!=head)
            curr=curr->next;
        curr->next=temp;
        temp->next=head;
    }
    return temp;
}

// insert at head efficient
Node *insertBegin(Node * head,int x){
    Node *temp=new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;    
    }
    else{

        temp->next=head->next;
        head->next=temp;

        int t=head->data;
        head->data=temp->data;
        temp->data=t;

        return head;
    }
}

// insert at tail naive
Node *insertEnd(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;    
    }
    else{
        Node *curr=head;
        while(curr->next!=head)
            curr=curr->next;
        curr->next=temp;
        temp->next=head;
        return head;
    }
}

// insert at tail efficient
Node *insertEnd(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;    
    }
    else{
        temp->next=head->next;
        head->next=temp;

        int t=head->data;
        head->data=temp->data;
        temp->data=t;

        return temp;
    }
}

// delete at head naive
Node *delHead(Node *head){
    if(head==NULL)return NULL;
    if(head->next==head){
        delete head;
        return NULL;
    }
    Node *curr=head;
    while(curr->next!=head)
        curr=curr->next;
    curr->next=head->next;
    delete head;
    return (curr->next);
}

// delete at head efficient
Node *delHead(Node *head){
    if(head==NULL)return NULL;
    if(head->next==head){
        delete head;
        return NULL;
    }
    head->data=head->next->data;
    Node *temp=head->next;
    head->next=head->next->next;
    delete temp;
    return head;
}

// delete at Kth
Node *deleteKth(Node *head,int k){
    if(head==NULL)return head;
    if(k==1)return delHead(head);
        Node *curr=head;
    for(int i=0;i<k-2;i++)
        curr=curr->next;
    Node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=head;
	head=insertBegin(head,15);
	printlist(head);
    cout<<endl;
    head=insertEnd(head,15);
	printlist(head);
    cout<<endl;
    head=delHead(head);
	printlist(head);
    cout<<endl;
    head=deleteKth(head,3);
	printlist(head);

	return 0;
} 
