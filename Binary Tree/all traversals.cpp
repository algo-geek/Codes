#include <bits/stdc++.h>
using namespace std;

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

void allTraversal(Node * root, vector < int > & pre, vector < int > & in , vector < int > & post) {
  stack < pair < Node * , int >> st;
  st.push({
    root,
    1
  });
  if (root == NULL) return;

  while (!st.empty()) {
    auto it = st.top();
    st.pop();

    if (it.second == 1) {
      pre.push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> left != NULL) {
        st.push({
          it.first -> left,
          1
        });
      }
    }


    else if (it.second == 2) {
      in .push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> right != NULL) {
        st.push({
          it.first -> right,
          1
        });
      }
    }

    else {
      post.push_back(it.first -> data);
    }
  }
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
    
    vector < int > pre, in , post;
    allTraversal(root, pre, in , post);

    cout << "Preorder Traversal is : ";
    for (auto i: pre) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Inorder Traversal is : ";
    for (auto i: in ) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Postorder Traversal is : ";
    for (auto i: post) {
        cout << i << " ";
    }
    cout << endl;
}