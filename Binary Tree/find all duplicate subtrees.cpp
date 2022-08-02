// time:  O(N^2)  Since string copying takes O(n) extra time.
// space: O(N^2) Since we are hashing a string for each node and length of this string can be of the order N.
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

string inorder(Node* node, unordered_map<string, int>& m)
{
    if (!node)
        return "";
 
    string str = "(";
    str += inorder(node->left, m);
    str += to_string(node->data);
    str += inorder(node->right, m);
    str += ")";
 
    // Subtree already present (Note: we use unordered_map instead of unordered_set
    // because we want to print multiple duplicates only once,
    // consider example of 4 in above subtree, it should be printed only once.
    if (m[str] == 1)
        cout << node->data << " ";
 
    m[str]++;
 
    return str;
}
 
void printAllDups(Node* root)
{
    unordered_map<string, int> m;
    inorder(root, m);
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(2);
    root->right->left->left = new Node(4);
    root->right->right = new Node(4);
    printAllDups(root);
 
    return 0;
}


