// level order traversal
// take a flag
// if level = k, mark flag true
// break from loop
int sumAtK(Node* root, int k)
{
    if(root==NULL)
    return -1;
    
    queue<Node*>q;
    
    q.push(root);
    q.push(NULL);
    int l=0, s=0;
    int flag = 0;
    
    while(!q.empty())
    {
        int size = que.size();

        while (size--) {
            Node* node=q.front();
            q.pop();
            
            if(l==k)
            {
                flag=1;
                s+=node->data;
            }
            else
            {
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            
            l++;
        }
    }
    return s;
}

int main()
{
    struct Node* root=new Node(1); //root pointer points to a new Node
    root->left=new Node(2);
    root->right=new Node(3);
    
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    
    cout<<sumAtK(root, 2);

}
