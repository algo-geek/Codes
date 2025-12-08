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
    return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);   
}
// iterative preorder
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*>s;
    vector<int>v;
    while(root || !s.empty()){
        if(root){       
            s.push(root);
            v.push_back(root->val);
            root=root->left;
        }
        else{
            root=s.top();
            s.pop();
            root=root->right;
        }
    }
    return v;
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
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*>s;
    vector<int>v;
     while(root || !s.empty()){
        if(root){
            s.push(root);
            root=root->left;
        }
        else{
            root=s.top();
            s.pop();
            v.push_back(root->val);
            root=root->right;
        }
    }
    return v;
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

// iterative postorder
vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*>s;
    vector<int>v;
    while(root || !s.empty()){
        if(root){       
            s.push(root);
            v.push_back(root->val);
            root=root->right;
        }
        else{
            root=s.top();
            s.pop();
            root=root->left;
        }
    }
    reverse(v.begin(), v.end());
    return v;
}
