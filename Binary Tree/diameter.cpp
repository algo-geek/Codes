// if diamete passing through root node: lh+rh+1
// else, max(ld, rd)

// naive // O(n^2) Time and O(h) Space
int height(Node* root)
{
    if(root==NULL)
    return 0;
    
    int lh=height(root->left);
    int rh=height(root->right);
    
    return max(lh, rh)+1;
}

int diameter(Node* root)
{
    if(root==NULL)
    return 0;
    
    int lh=height(root->left);
    int rh=height(root->right);
    int currD=lh+rh+1;
    
    int ld=diameter(root->left);
    int rd=diameter(root->right);
    
    return max(currD, max(ld, rd));
}

// efficient // O(n) Time and O(h) Space
// For each node, the longest path passing through it 
// is the sum of the heights of its left and right subtrees. 
int res=0;
int height2(Node *root){
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    res=max(res,1+lh+rh);
    
        return 1+max(lh,rh);
}

