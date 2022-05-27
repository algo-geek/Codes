//naive
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

int maxValue(Node *root){
    if (root == NULL) 
        return INT_MIN; 
  
    int res = root->key; 
    int lres = maxValue(root->left); 
    int rres = maxValue(root->right); 
    if (lres > res) 
        res = lres; 
    if (rres > res) 
        res = rres; 
    return res; 
}

int minValue(Node* root) 
{ 
    if (root == NULL) 
      return INT_MAX; 
  
    int res = root->key; 
    int lres = minValue(root->left); 
    int rres = minValue(root->right); 
    if (lres < res) 
      res = lres; 
    if (rres < res) 
      res = rres; 
    return res; 
} 
int isBS(Node* root)  
{  
  if (root == NULL)  
    return 1;  
      
  if (root->left!=NULL && maxValue(root->left) > root->key)  
    return 0;  
      
  if (root->right!=NULL && minValue(root->right) < root->key)  
    return 0;  
    
  if (!isBS(root->left) || !isBS(root->right))  
    return 0;  
      
  return 1;  
}

int main() {
	
	Node *root = new Node(4);  
    root->left = new Node(2);  
    root->right = new Node(5);  
    root->left->left = new Node(1);  
    root->left->right = new Node(3);  
      
    if(isBS(root))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";  
          
    return 0;  
	
}

//efficient
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

bool isBST(Node* root,int min, int max)  
{  
  if (root == NULL)  
    return true;  
      
  return ( root->key>min && root->key<max && 
            isBST(root->left,min,root->key) && isBST(root->right,root->key,max));  
}

int main() {
	
	Node *root = new Node(4);  
    root->left = new Node(2);  
    root->right = new Node(5);  
    root->left->left = new Node(1);  
    root->left->right = new Node(3);  
      
    if(isBST(root,INT_MIN,INT_MAX))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";  
          
    return 0;  
	
}

//optimised
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

int prevv=INT_MIN;
bool isBST(Node* root)  
{  
    if (root == NULL)  
        return true;  
    
    if(isBST(root->left)==false)return false;
    
    if(root->key<=prevv)return false;
    prevv=root->key;
    
    return isBST(root->right);
}

int main() {
	
	Node *root = new Node(4);  
    root->left = new Node(2);  
    root->right = new Node(5);  
    root->left->left = new Node(1);  
    root->left->right = new Node(3);  
      
    if(isBST(root))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";  
          
    return 0;  
	
}