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

void vSumR(Node *root, int h, map<int,int> &mp)
{
    if(root==NULL)
    return;

    vSumR(root->left,h-1,mp);
    mp[h]+=root->key;
    vSumR(root->right,h+1,mp);
}

void vSum(Node *root)
{
    map<int, int>mp;
    vSumR(root,0,mp);

    for(auto x:mp)
    cout<<x.second<<" ";
}

int main() {
	
	Node *root = new Node(10);  
    root->left = new Node(20);  
    root->right = new Node(50);  
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    
    vSum(root);
          
    return 0;  
	
}