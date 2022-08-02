#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left; 
    struct Node* right;
    
    Node(int val) 
    {
        data=val;
        left=NULL;
        right=NULL;
    }
    
};

int height(Node* root)
{
    if(root==NULL)
    return 0;
    
    int lh=height(root->left);
    int rh=height(root->right);
    
    return max(lh, rh)+1;
}

bool isBalanced(Node* root)
{
    if(root==NULL)
    return true;
    
    int lh=height(root->left);
    int rh=height(root->right);
    
    return (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
}

// efficient
int isBalanced2(Node *root){
    if(root==NULL)
        return 0;
    int lh=isBalanced2(root->left);
    if(lh==-1)return -1;
    int rh=isBalanced2(root->right);
    if(rh==-1)return -1;
    
    if(abs(lh-rh)>1)
        return -1; 
    else
        return max(lh,rh)+1;
}

// 3
bool isBalanced3(Node* root, int* h)
{
    if(root==NULL)
    {
        return true;
    }
    
    int lh=0;
    int rh=0;
    
    if(isBalanced3(root->left, &lh)==false)
    {
        return false;
    }
    if(isBalanced3(root->right, &rh)==false)
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
    struct Node* root=new Node(1); 
    root->left=new Node(2);
    root->right=new Node(3);
    
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    
    // 1
    if(isBalanced(root))
    {
        cout<<"Balanced"<<endl;
    }
    else
    {
        cout<<"Unbalanced"<<endl;
    }

    // 2
    if(isBalanced2(root))
	    cout<<"Balanced";
	else
	    cout<<"Not Balanced";

    // 3
    int h=0;
    if(isBalanced3(root, &h))
    {
        cout<<"Balanced"<<endl;
    }
    else
    {
        cout<<"Unbalanced"<<endl;
    }

}