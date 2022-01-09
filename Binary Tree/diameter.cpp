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

int diameter(Node* root)
{
    if(root==NULL)
    return 0;
    
    int lh=height(root->left);
    int rh=height(root->right);
    int currD=lh+rh+1;
    
    int ld=diameter(root->left);
    int rd=diameter(root->right);
    
    return max(currD, max(ld, rd));
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
    
    cout<<diameter(root);

}