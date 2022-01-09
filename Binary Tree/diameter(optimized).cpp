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

int diameter(Node* root, int* h)
{
    if(root==NULL)
    {
        *h=0;
        return 0;
    }
    
    int lh=0;
    int rh=0;
    
    
    int ld=diameter(root->left, &lh);
    int rd=diameter(root->right, &rh);
    
    int currD=lh+rh+1;
    *h=max(lh, rh)+1;
    
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
    
    int h=0;
    cout<<diameter(root, &h);

}