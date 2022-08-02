// O(n) time & space
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

void sumOfLongRootToLeafPath(Node* root, int sum, int len, int& maxLen, int& maxSum)
{
    // we have traversed a root to leaf path
    if (!root) 
    {
        if (maxLen < len) 
        {
            maxLen = len;
            maxSum = sum;
        } 
        else if (maxLen == len && maxSum < sum)
            maxSum = sum;
        return;
    }
 
    sumOfLongRootToLeafPath(root->left, sum + root->data, len + 1, maxLen, maxSum);
    sumOfLongRootToLeafPath(root->right, sum + root->data, len + 1, maxLen, maxSum);
}
 
int sumOfLongRootToLeafPathUtil(Node* root)
{
    if (!root)
        return 0;
 
    int maxSum = INT_MIN, maxLen = 0;

    sumOfLongRootToLeafPath(root, 0, 0, maxLen, maxSum);
 
    return maxSum;
}

int main()
{
  struct Node* root = new Node(4);         /*   4        */
    root->left = new Node(2);         /*       / \       */
    root->right = new Node(5);        /*      2   5      */
    root->left->left = new Node(7);   /*     / \ / \     */
    root->left->right = new Node(1);  /*    7  1 2  3    */
    root->right->left = new Node(2);  /*      /          */
    root->right->right = new Node(3); /*     6           */
    root->left->right->left = new Node(6);
 
    cout << "Sum = " << sumOfLongRootToLeafPathUtil(root);
 
    return 0;
}


