
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

bool path(Node* root, int k, vector<int>&v)
{
    if(root==NULL)
    return false;
    
    v.push_back(root->data);
    
    if(root->data==k)
    {
        return true;
    }
    if(path(root->left, k, v) || path(root->right, k, v))
    {
        return true;
    }
    v.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2)
{
    vector<int>p1, p2;
    
    if(!path(root, n1, p1) || !path(root, n2, p2))
    return -1;
    
    int r;
    
    for(r=0;r<p1.size() && p2.size();r++)
    {
        if(p1[r]!=p2[r])
        break;
    }
    
    return p1[r-1];
}

Node* LCA2(Node* root, int n1, int n2)
{
    if(root==NULL)
    return NULL;
    
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
    
    Node* leftlca=LCA2(root->left, n1, n2);
    Node* rightlca=LCA2(root->right, n1, n2);
    
    if(leftlca && rightlca)
    {
        return root;
    }
    if(leftlca!=NULL)
    {
        return leftlca;
    }
    return rightlca;
}


int main()
{
    struct Node* root=new Node(1); //root pointer points to a new Node
    root->left=new Node(2);
    root->right=new Node(3);
    
    root->left->left=new Node(4);
    
    root->right->left=new Node(5);
    root->right->right=new Node(6);
    
    root->right->left->left=new Node(7);
    
    int n1=7, n2=6;
    
    // method 1
    int lca=LCA(root, n1, n2);
    
    if(lca==-1)
    cout<<"lca doesn't exist"<<endl;
    else
    cout<<"lca= "<<lca<<endl;
    
    
    // method 2
    Node* lca2=LCA2(root, n1, n2);
    
    if(lca2==NULL)
    cout<<"lca2 doesn't exist"<<endl;
    else
    cout<<"lca2= "<<lca2->data<<endl;
 
}
