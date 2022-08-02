// time: O(n*h*h) // space: O(h)
#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

void printKPathUtil(Node* root, vector<int>& path, int k)
{
	if (!root)
		return;

	path.push_back(root->data);

	printKPathUtil(root->left, path, k);
	printKPathUtil(root->right, path, k);

	// check if there's any k sum path that
	// terminates at this node
	// Traverse the entire path as
	// there can be negative elements too
	int f = 0;
	for (int j = path.size() - 1; j >= 0; j--) {
		f += path[j];

		// If path sum is k, print the path
		if (f == k)
		{
		    for (int i = j; i < path.size(); i++)
		        cout << path[i] << " ";
	        cout << endl;
		}
	}

	// Remove the current element from the path
	path.pop_back();
}


int main()
{
	Node* root = new Node(1);
	root->left = new Node(3);
	root->left->left = new Node(2);
	root->left->right = new Node(1);
	root->left->right->left = new Node(1);
	root->right = new Node(-1);
	root->right->left = new Node(4);
	root->right->left->left = new Node(1);
	root->right->left->right = new Node(2);
	root->right->right = new Node(5);
	root->right->right->right = new Node(2);

	int k = 5;
	vector<int> path;
	printKPathUtil(root, path, k);

	return 0;
}
