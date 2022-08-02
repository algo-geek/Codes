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


void printBoundaryLeft(Node* root)
{
    if (root == NULL)
        return;
 
    if (root->left) 
    {
        // for top down order, print the node and then call for left subtree
        cout << root->data << " ";
        printBoundaryLeft(root->left);
    }
    else if (root->right)
    {
        cout << root->data << " ";
        printBoundaryLeft(root->right);
    }
    // do nothing if it is a leaf node to avoid duplicates in output
}
 
void printLeaves(Node* root)
{
    if (root == NULL)
        return;
 
    printLeaves(root->left);
 
    // Print it if it is a leaf node
    if (!(root->left) && !(root->right))
        cout << root->data << " ";
 
    printLeaves(root->right);
}
  
  
void printBoundaryRight(Node* root)
{
    if (root == NULL)
        return;
 
    if (root->right) 
    {
        // to ensure bottom up order, first call for right subtree and then print root
        printBoundaryRight(root->right);
        cout << root->data << " ";
    }
    else if (root->left) 
    {
        printBoundaryRight(root->left);
        cout << root->data << " ";
    }
    // do nothing if it is a leaf node to avoid duplicates in output
}
 

void printBoundary(Node* root)
{
    if (root == nullptr)
        return;
 
    cout << root->data << " ";
 
    // Print the left boundary in top-down manner.
    printBoundaryLeft(root->left);
 
    // Print all leaf nodes
    printLeaves(root->left);
    printLeaves(root->right);
 
    // Print the right boundary in bottom-up manner
    printBoundaryRight(root->right);
}

int main()
{
    struct Node* root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);
    
    printBoundary(root);

}