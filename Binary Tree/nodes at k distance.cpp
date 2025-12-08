// using recursion and find the target node. 
// Find all nodes in left and right subtree of target node at dis k. 
// for all nodes in path of target node, find all nodes in opposite subtree 
// that are at the distance of  (k - distance of target node).

// O(nlogn) Time and O(h) Space

// Find nodes at distance k from
// target node in subtree.
void subtree(Node* root, int k)
{
    if(root==NULL || k<0)
    return;
    
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    
    subtree(root->left, k-1);
    subtree(root->right, k-1);
}

// Function which returns the distance of a node to
// target node. Returns -1 if target is not found.
int printNodesAtK(Node* root, Node* t, int k)
{
    if(root==NULL)
    return -1;
    
    if(root==t)
    {
        subtree(root, k);
        return 0;
    }
    
    int dl=printNodesAtK(root->left, t, k);
    // If target node is found in left
    // subtree, find all nodes at distance
    // k-left in right subtree.
    if(dl!=-1)
    {
        if(k-dl==0)
        cout<<root->data<<" ";
        else
        subtree(root->right, k-dl-1);
        
        return dl+1;
    }
    // If target node is found in right
    // subtree, find all nodes at distance
    // k-right in left subtree.
    int dr=printNodesAtK(root->right, t, k);
    if(dr!=-1)
    {
        if(dr+1==k)
        cout<<root->data<<" ";
        else
        subtree(root->left, k-dr-1);
        
        return dr+1;
    }
    
    return -1;
    
}

int main()
{
    struct Node* root=new Node(1); //root pointer points to a new Node
    root->left=new Node(5);
    root->right=new Node(2);
    
    root->left->left=new Node(6);
    
    root->left->left->right=new Node(7);
    root->left->left->right->left=new Node(8);
    root->left->left->right->right=new Node(9);
    
    root->right->left=new Node(3);
    root->right->right=new Node(4);
    
    printNodesAtK(root, root->left, 3);

}
