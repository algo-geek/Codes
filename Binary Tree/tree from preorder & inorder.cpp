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

void preorder(struct Node* root)
{
    if(root==NULL)
    {
        // cout<<"0"<<" ";
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
    
}

int search(int inorder[], int st, int end, int curr)
{
    for(int i=st;i<=end;i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int st, int end)
{
    static int idx=0;
    
    if(st>end)
    return NULL;
    
    int curr=preorder[idx];
    idx++;
    
    Node* node=new Node(curr);
    
    if(st==end)// if there is only 1 element in inorder, it has no left & right subtree
    {
        return node;
    }
    
    int pos=search(inorder, st, end, curr);
    node->left=buildTree(preorder, inorder, st, pos-1);
    node->right=buildTree(preorder, inorder, pos+1, end);
    
    return node;
}

void inorderPrint(Node* root)
{
    if(root==NULL)
    return;
    
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main()
{
    int preorder[]={1, 2, 4, 3, 5};
    int inorder[]={4, 2, 1, 5, 3};
    
    Node* root=buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);
}