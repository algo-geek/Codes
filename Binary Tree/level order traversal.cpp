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

// 1
void printLevel(Node *root){
    if(root==NULL)return;
    queue<Node *>q;
    q.push(root);
    while(q.empty()==false){
        Node *curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}


// 2 
void printLevelOrder(Node* root)
{
    if(root==NULL)
    return;
    
    queue<Node*>q;
    
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        Node* node=q.front();
        q.pop();
        
        if(node!=NULL)
        {
            cout<<node->data<<" ";
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }
}

// 3
void printLevel2(Node *root){
    if(root==NULL)return;
    queue<Node *>q;
    q.push(root);
    while(q.empty()==false){
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            Node *curr=q.front();
            q.pop();
            cout<<curr->data<<" ";

            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        cout<<"\n";
    }
} 

// reverse level order
void reverseLevelOrder(Node* root)
{
	stack <Node *> S;
	queue <Node *> Q;
	Q.push(root);

	while (Q.empty() == false)
	{
	    int count=Q.size();
        for(int i=0;i<count;i++)
        {
		root = Q.front();
		Q.pop();
		S.push(root);

		if (root->right)
			Q.push(root->right); 

		if (root->left)
			Q.push(root->left);
        }
        S.push(NULL);
	}

	S.pop(); // to remove the last NULL entered into stack
	while (S.empty() == false)
	{
		root = S.top();
		
		if(root==NULL)
		cout<<endl;
		else
		cout << root->data << " ";
		
		S.pop();
	}
}

int main()
{
    struct Node* root=new Node(1); 
    root->left=new Node(2);
    root->right=new Node(3);
    
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    
    printLevel(root);
    printLevelOrder(root);
    printLevel2(root);
    cout << "Level Order traversal of binary tree is \n";
	reverseLevelOrder(root);

}