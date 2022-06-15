// naive
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

// reverse inorder
void printKth(Node *root, int k, int &count){
    if(root!=NULL){
        printKth(root->right,k,count);
        count++;
        if(count==k)
            {cout<<root->key; return;}
        printKth(root->left,k,count);
    }
} 

int main() {
	
	Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int k=3;
	int count=0;
	cout<<"Kth Smallest: ";
	printKth(root,k,count);
	
	return 0;
}

// efficient
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right;
  int rCount;
  Node(int k){
      key=k;
      left=right=NULL;
      rCount=0;
  }
};

Node* insert(Node* root, int x)
{
    if (root == NULL)
        return new Node(x);

    if (x < root->key) {
        root->left = insert(root->left, x);
        
    }
 
    else if (x > root->key)
        {
            root->right = insert(root->right, x);
            root->rCount++;
        }
    return root;
}

Node* kthLargest(Node* root, int k)
{
    if (root == NULL)
        return NULL;
 
    int count = root->rCount + 1;
    if (count == k)
        return root;
 
    if (count > k)
        return kthLargest(root->right, k);
 
    return kthLargest(root->left, k - count);
}

int main() {
	
	Node* root = NULL;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
 
    for (int x : keys)
        root = insert(root, x);
 
    int k = 4;
    Node* res = kthLargest(root, k);
    if (res == NULL)
        cout << "There are less than k nodes in the BST";
    else
        cout << "kthLargest Element is " << res->key;
    return 0;
	
}