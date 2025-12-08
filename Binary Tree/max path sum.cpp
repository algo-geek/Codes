// O(n) Time and O(h) Recursive Space
// use postorder traversal. 
// At each node, calculate left and right path sums, 
// and update a global maximum with (left + node + right). 
// Return the node’s value plus the larger side upward.
int maxpathsum(Node* root, int &ans)
{
    if(root==NULL)
    return 0;
    
    int l=max(0,maxpathsum(root->left, ans));
    int r=max(0,maxpathsum(root->right, ans));
    
    ans=max(ans, l + r + root->data);
    return root->data + max(l, r);
}

int maxsum(Node* root)
{
    int ans=INT_MIN;
    maxpathsum(root, ans);
    return ans;
}
