//inorder traversal solution
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

void treeToList(Node *root, vector<int> &list)
{
    if(root==NULL)
    return;
    
    treeToList(root->left, list);
    list.push_back(root->key);
    treeToList(root->right, list);
    
}


bool isPairPresent(Node *root, int sum)
{
    vector<int>v;
    treeToList(root, v);

    int s=0, e=v.size()-1;
    while(s<e)
    {
        if(v[s]+v[e]==sum)
        {
            cout<<v[s]<<" "<<v[e]<<endl;
            return true;
        }
        if(v[s]+v[e]<sum)
        s++;
        if(v[s]+v[e]>sum)
        e--;
    }
    return false;

}

int main()
{
    Node *root = new Node(10);  
    root->left = new Node(8);  
    root->right = new Node(20);  
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(30);  
    root->right->right->left = new Node(25);
        
    int sum=33;
        
    cout<<isPairPresent(root,sum);

    return 0;
}

// hashing solution
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

bool isPairPresent(Node *root, int sum, unordered_set<int> &s)
{
    if(root==NULL)
    return false;

    if(isPairPresent(root->left,sum,s)==true)
        return true;

    if(s.find(sum-root->key)!=s.end())
    return true;
    else
    s.insert(root->key);

    return isPairPresent(root->right,sum,s);

}

int main()
{
    Node *root = new Node(10);  
    root->left = new Node(8);  
    root->right = new Node(20);  
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(30);  
    root->right->right->left = new Node(25);
        
    int sum=33;
    unordered_set<int> s;
        
    cout<<isPairPresent(root,sum,s);

    return 0;
}