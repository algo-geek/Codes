// reverse postorder: root-right-left order
// map to store indices of item in inorder for O(1) lookup.
// Start from the beginning of the reversed postorder array.
// The current element becomes the root.
// Recur for the right subtree first, then the left, because of the reversed postorder.
// Use the inorder index map to divide the tree into left and right subtrees.

// revised
TreeNode* build(vector<int>& postorder, map<int,int> &m, int strt, int end, int&curridx){
        if(strt>end)return NULL;      
        TreeNode* root=new TreeNode(postorder[curridx]);
        int val=postorder[curridx++];
        root->right=build(postorder, m, m[val]+1, end, curridx);
        root->left=build(postorder, m, strt, m[val]-1, curridx);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>m;
        reverse(postorder.begin(), postorder.end());
        int s=postorder.size();
        for(int i=0;i<s;i++){
            m[inorder[i]]=i;
        }
        int curr=0;
        return build(postorder, m, 0, s-1, curr);
}

// old
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

Node* buildTree(int postorder[], int inorder[], int st, int end)
{
    static int idx=4;
    
    if(st>end)
    return NULL;
    
    int curr=postorder[idx];
    idx--;
    
    Node* node=new Node(curr);
    
    if(st==end)// if there is only 1 element in inorder, it has no left & right subtree
    {
        return node;
    }
    
    int pos=search(inorder, st, end, curr);
    node->right=buildTree(postorder, inorder, pos+1, end);
    node->left=buildTree(postorder, inorder, st, pos-1);
    
    
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
    int postorder[]={4, 2, 5, 3, 1};
    int inorder[]={4, 2, 1, 5, 3};
    
    Node* root=buildTree(postorder, inorder, 0, 4);
    inorderPrint(root);
}
