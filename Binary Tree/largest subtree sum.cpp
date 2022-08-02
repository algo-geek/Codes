// O(n) time & space
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    struct Node* left; 
    struct Node* right;
    
    Node(int val) 
    {
        key=val;
        left=NULL;
        right=NULL;
    }
    
};

int findLargestSubtreeSumUtil(Node* root, int& ans)
{
    if (root == NULL)    
        return 0;
     
    int currSum = root->key +
                    findLargestSubtreeSumUtil(root->left, ans) + 
                    findLargestSubtreeSumUtil(root->right, ans);
 
    ans = max(ans, currSum);
 
    // Return current subtree sum to its parent node.
    return currSum;
}
 
int findLargestSubtreeSum(Node* root)
{
    if (root == NULL)    
        return 0;
     
    int ans = INT_MIN;
 
    findLargestSubtreeSumUtil(root, ans);
 
    return ans;
}

int main()
{
  struct Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);
  
   cout << findLargestSubtreeSum(root);
    
  return 0;
}


