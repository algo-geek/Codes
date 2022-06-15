#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left;
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

void vTraversal(Node *root)
{
    map<int,vector<int>>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});

    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        Node *curr=x.first;
        int h=x.second;
        mp[h].push_back(curr->key);

        if(curr->left!=NULL)
        q.push({curr->left, h-1});

        if(curr->right!=NULL)
        q.push({curr->right, h+1});

    }

    for(auto x:mp){
        for(int y:x.second)
            cout<<y<<" ";
        cout<<endl;
    }
}

int main() {
	
	Node *root = new Node(10);  
    root->left = new Node(20);  
    root->right = new Node(30);  
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    
    vTraversal(root);
          
    return 0;  
	
}