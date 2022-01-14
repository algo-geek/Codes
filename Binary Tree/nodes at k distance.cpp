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


// case 1

void subtree(Node* root, int k)
{
    if(root==NULL || k<0)
    return;
    
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    
    subtree(root->left, k-1);
    subtree(root->right, k-1);
}

//case 2

int printNodesAtK(Node* root, Node* t, int k)
{
    if(root==NULL)
    return -1;
    
    if(root==t)
    {
        subtree(root, k);
        return 0;
    }
    
    int dl=printNodesAtK(root->left, t, k);
    
    if(dl!=-1)
    {
        if(dl+1==k)
        cout<<root->data<<" ";
        else
        subtree(root->right, k-dl-2);
        
        return dl+1;
    }
    
    int dr=printNodesAtK(root->right, t, k);
    if(dr!=-1)
    {
        if(dr+1==k)
        cout<<root->data<<" ";
        else
        subtree(root->left, k-dr-2);
        
        return dr+1;
    }
    
    return -1;
    
}

int main()
{
    struct Node* root=new Node(1); //root pointer points to a new Node
    root->left=new Node(5);
    root->right=new Node(2);
    
    root->left->left=new Node(6);
    
    root->left->left->right=new Node(7);
    root->left->left->right->left=new Node(8);
    root->left->left->right->right=new Node(9);
    
    root->right->left=new Node(3);
    root->right->right=new Node(4);
    
    printNodesAtK(root, root->left, 3);

}
