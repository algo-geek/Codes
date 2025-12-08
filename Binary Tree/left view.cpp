
void leftView(Node* root)
{
    if(root==NULL)
    return;
    
    queue<Node*>q;
    
    q.push(root);
    
    while(!q.empty())
    {
        int n=q.size();
        
        for(int i=0;i<n;i++)
        {
            Node* node=q.front();
            q.pop();
            
            if(i==0)
            {
                cout<<node->data<<" ";
            }
            
            if(node->left!=NULL)
            {
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
        }
        
    }
}
