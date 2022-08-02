// merge sort

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;
 
    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node* merge(Node* a, Node* b)
{
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;
 
    Node* result;
 
    if (a->data < b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
 
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}
 
Node* flatten(Node* root)
{
    if (root == NULL || root->next == NULL)
        return root;
 
    // Recur for list on right
    root->next = flatten(root->next);
 
    // merge
    root = merge(root, root->next);
 
    // Return the root
    // it will be in turn merged with its left
    return root;
}

void printList(Node *head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << endl;
}
 
int main()
{
  Node* head=new Node(5);
  auto temp=head;
  auto bt=head;
  bt->bottom=new Node(7);
  bt->bottom->bottom=new Node(8);
  bt->bottom->bottom->bottom=new Node(30);
  temp->next=new Node(10);
   
  temp=temp->next;
  bt=temp;
  bt->bottom=new Node(20);
  temp->next=new Node(19);
  temp=temp->next;
  bt=temp;
  bt->bottom=new Node(22);
  bt->bottom->bottom=new Node(50);
  temp->next=new Node(28);
  temp=temp->next;
  bt=temp;
  bt->bottom=new Node(35);
  bt->bottom->bottom=new Node(40);
  bt->bottom->bottom->bottom=new Node(45);
   
  head = flatten(head);
  printList(head);
  return 0;
}

// priority queue 1
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;
 
    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

struct mycomp {
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};
void flatten2(Node* root)
{
    priority_queue<Node*, vector<Node*>, mycomp> p;
    while (root!=NULL) 
    {
        p.push(root);
        root = root->next;
    }
   
    while (!p.empty()) 
    {
        auto k = p.top();
        p.pop();
        cout << k->data << " ";
        if (k->bottom)
            p.push(k->bottom);
    }
    
}
 
int main(void)
{
  Node* head=new Node(5);
  auto temp=head;
  auto bt=head;
  bt->bottom=new Node(7);
  bt->bottom->bottom=new Node(8);
  bt->bottom->bottom->bottom=new Node(30);
  temp->next=new Node(10);
   
  temp=temp->next;
  bt=temp;
  bt->bottom=new Node(20);
  temp->next=new Node(19);
  temp=temp->next;
  bt=temp;
  bt->bottom=new Node(22);
  bt->bottom->bottom=new Node(50);
  temp->next=new Node(28);
  temp=temp->next;
  bt=temp;
  bt->bottom=new Node(35);
  bt->bottom->bottom=new Node(40);
  bt->bottom->bottom->bottom=new Node(45);
   
  flatten2(head);
  cout << endl;
  return 0;
}

// // priority queue 2
