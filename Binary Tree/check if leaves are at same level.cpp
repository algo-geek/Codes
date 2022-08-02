// O(n) time & space

// recursive
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

bool checkUtil(struct Node *root, int level, int *leafLevel)
{
  if (root == NULL) return true;

  if (root->left == NULL && root->right == NULL)
  {
    if (*leafLevel == 0)
    {
      *leafLevel = level; 
      return true;
    }

    return (level == *leafLevel);
  }

  return checkUtil(root->left, level + 1, leafLevel) && checkUtil(root->right, level + 1, leafLevel);
}

bool check(struct Node *root)
{
  int level = 0, leafLevel = 0;
  return checkUtil(root, level, &leafLevel);
}

int main()
{
  struct Node *root = new Node(12);
  root->left = new Node(5);
  root->left->left = new Node(3);
  root->left->right = new Node(9);
  root->left->left->left = new Node(1);
  root->left->right->left = new Node(1);
  if (check(root))
    cout << "Leaves are at same level\n";
  else
    cout << "Leaves are not at same level\n";
    
  return 0;
}

// iterative
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

int check2(Node* root)
{
    if (!root)
        return 1;
  
    queue<Node*> q;
    q.push(root);
  
    int result = INT_MAX;
     int level = 0;
 
    while (!q.empty()) {
        int size = q.size();
        level += 1;
 
        while(size > 0)
        {
            Node* temp = q.front();
            q.pop();
         
            if (temp->left) 
            {
                q.push(temp->left);
 
                // if its leaf node
                if(!temp->left->right && !temp->left->left)
                {
 
                    // if it's first leaf node
                    if (result == INT_MAX)
                        result = level;
                     
                    else if (result != level)
                        return 0;                   
                }
            }
              
            if (temp->right)
            {
                q.push(temp->right);
 
                // if it's leaf node
                if (!temp->right->left && !temp->right->right)
 
                    // if it's first leaf node till now
                    if (result == INT_MAX)
                        result = level;

                    else if(result != level)
                        return 0;
                     
               }
               size -= 1;
        }   
    }
     
    return 1;
}

int main()
{
  struct Node *root = new Node(12);
  root->left = new Node(5);
  root->left->left = new Node(3);
  root->left->right = new Node(9);
  root->left->left->left = new Node(1);
  root->left->right->left = new Node(1);
  if (check2(root))
    cout << "Leaves are at same level\n";
  else
    cout << "Leaves are not at same level\n";
    
  return 0;
}



