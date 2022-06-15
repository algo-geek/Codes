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

// recursive preorder
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

// iterative preorder 1
void preorder2(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }  
    stack<Node *>s;
    s.push(root);

    while(!s.empty())
    {
        Node *curr=s.top();
        cout<<curr->data<<" ";
        s.pop();

        if(curr->right)
        s.push(curr->right);

        if(curr->left)
        s.push(curr->left);

    }  
}

// iterative preorder 2
void preorder2(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }  
    stack<Node *>s;
    Node *curr=root;

    while(curr!=NULL || !s.empty())
    {
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";

            if(curr->right)
            s.push(curr->right);

            curr=curr->left;
        }
        
        
       if(!s.empty())
       {
            curr=s.top();
            s.pop();
       }

    } 
}

// recursive inorder
void inorder(struct Node* root)
{
    if(root==NULL)
    return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//iterative inorder
void inorder2(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }  
    stack<Node *>s;
    Node *curr=root;

    while(curr!=NULL || !s.empty())
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
       
    } 
}

// recursive postorder
void postorder(struct Node* root)
{
    if(root==NULL)
    return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
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
    
    preorder(root);
    cout<<endl;
    preorder2(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    inorder2(root);
    cout<<endl;
    postorder(root);
}