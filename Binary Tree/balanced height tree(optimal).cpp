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

bool isBalanced(Node* root, int* h)
{
    if(root==NULL)
    {
        return true;
    }
    
    int lh=0;
    int rh=0;
    
    if(isBalanced(root->left, &lh)==false)
    {
        return false;
    }
    if(isBalanced(root->right, &rh)==false)
    {
        return false;
    }
    
    *h=max(lh, rh)+1;
    
    if(abs(lh-rh)<=1)
    return true;
    else
    return false;
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
    
    int h=0;
    
    if(isBalanced(root, &h))
    {
        cout<<"Balanced"<<endl;
    }
    else
    {
        cout<<"Unbalanced"<<endl;
    }

}