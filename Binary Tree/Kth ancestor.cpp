// level order traversal

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

void generateArray(Node *root, int ancestors[])
{
    ancestors[root->data] = -1;

    queue<Node*> q;
    q.push(root);
 
    while(!q.empty())
    {
        Node* temp  = q.front();
        q.pop();
 
        if (temp->left)
        {
            ancestors[temp->left->data] = temp->data;
            q.push(temp->left);
        }
 
        if (temp->right)
        {
            ancestors[temp->right->data] = temp->data;
            q.push(temp->right);
        }
    }
}

int kthAncestor(Node *root, int n, int k, int node)
{
    int ancestors[n+1] = {0};
 
    // generate first ancestor array
    generateArray(root,ancestors);
 
    // variable to track record of number of ancestors visited
    int count = 0;
 
    while (node!=-1)
    {  
        node = ancestors[node];
        count++;
 
        if(count==k)
            break;
    }
 
    // print Kth ancestor
    return node;
}

int main()
{
  struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
  
    int k = 2;
    int node = 5;
 
    cout<<kthAncestor(root,5,k,node);
    
  return 0;
}


// vector
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

bool RootToNode(Node* root, int key, vector<int>& v)
{
    if (root == NULL)
        return false;
 
    // Add current node to the path
    v.push_back(root->data);
 
    // If current node is the target node
    if (root->data == key)
        return true;
 
    // If the target node exists in
    // the left or the right sub-tree
    if (RootToNode(root->left, key, v)
        || RootToNode(root->right, key, v))
        return true;
 
    // Remove the last inserted node as
    // it is not a part of the path
    // from root to target
    v.pop_back();
    return false;
}

int main()
{
  struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    // Given node
    int target = 4;
 
    // Vector to store the path from root to the given node
    vector<int> v;
 
    // Find the path from root to the target node
    RootToNode(root, target, v);
 
    int k = 2;
 
    // Print the Kth ancestor
    if (k > v.size() - 1 || k <= 0)
        cout << -1;
    else
        cout << v[v.size() - 1 - k];
}


