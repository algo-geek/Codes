#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key=k;
        left=right=NULL;
    }
};

void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

Node *pre=NULL, *first=NULL, *second=NULL;
void fixBST(Node *root)
{
    if(root==NULL)
    return;

    fixBST(root->left);
    if(pre!=NULL && root->key<pre->key)
    {
        if(first==NULL)
        {
            first=pre;
        }
        second=root;
    }
    pre=root;

    return fixBST(root->right);
}

int main()
{
    Node *root=new Node(18);
    root->left = new Node(60);  
    root->right = new Node(70);  
    root->left->left = new Node(4);  
    root->right->left = new Node(8);
    root->right->right = new Node(80); 

    inorder(root);
    cout<<endl;

    fixBST(root);
    int t=first->key;
    first->key=second->key;
    second->key=t;

    inorder(root);

    return 0;
}