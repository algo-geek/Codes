// recursive
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      data=k;
      left=right=NULL;
  }
};

int maxLevel=0;
void printLeft(Node *root,int level){
    if(root==NULL)
        return;
        
    if(maxLevel<level)
    {
        cout<<root->data<<" ";
        maxLevel=level;
    }
    printLeft(root->left,level+1);
    printLeft(root->right,level+1);
}

void printLeftView(Node *root){
    printLeft(root,1);
}

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	
	printLeftView(root);
}

// iterative
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left; 
    struct Node* right;
    
    Node(int val) //constructor for node
    {
        data=val;
        left=NULL;
        right=NULL;
    }
    
};

void leftView(Node* root)
{
    if(root==NULL)
    return;
    
    queue<Node*>q;
    
    q.push(root);
    
    while(!q.empty())
    {
        int n=q.size();
        
        for(int i=0;i<n;i++)
        {
            Node* node=q.front();
            q.pop();
            
            if(i==0)
            {
                cout<<node->data<<" ";
            }
            
            if(node->left!=NULL)
            {
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
        }
        
        
    }
}

int main()
{
    struct Node* root=new Node(1); //root pointer points to a new Node
    root->left=new Node(2);
    root->right=new Node(3);
    
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    
    leftView(root);

}