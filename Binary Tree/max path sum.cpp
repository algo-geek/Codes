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

int maxpathsum(Node* root, int &ans)
{
    if(root==NULL)
    return 0;
    
    int l=maxpathsum(root->left, ans);
    int r=maxpathsum(root->right, ans);
    
    int nodemax=max(max(root->data, root->data+l+r), max(root->data+l, root->data+r)); 
    
    ans=max(ans, nodemax);
    
    int singlepathsum=max(root->data, max(root->data+l, root->data+r));
    return singlepathsum;
}

int maxsum(Node* root)
{
    int ans=INT_MIN;
    
    maxpathsum(root, ans);
    
    return ans;
}

int main()
{
    struct Node* root=new Node(1); //root pointer points to a new Node
    root->left=new Node(-12);
    root->right=new Node(3);
    
    root->left->left=new Node(4);
    
    root->right->left=new Node(5);
    root->right->right=new Node(-6);

    cout<<maxsum(root)<<endl;

 
}