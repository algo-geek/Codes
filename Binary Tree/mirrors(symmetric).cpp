// queue
bool isSymmetric(Node* root) {
    if (root == nullptr) {
        return true;
    }
    queue<Node*> q;
    // Initialize the queue with the left 
  	// and right subtrees
    q.push(root->left);
    q.push(root->right);

    while (!q.empty()) {
        
        Node* node1 = q.front(); 
        q.pop();
        Node* node2 = q.front();
        q.pop();

        // If both nodes are null, continue to the next pair
        if (node1 == nullptr && node2 == nullptr) {
            continue;
        }

        // If one node is null and the other is not, 
        // or the nodes' data do not match
        // then the tree is not symmetric
        if (node1 == nullptr || node2 == nullptr || 
            node1->data != node2->data) {
            return false;
        }

        // Enqueue children in opposite 
      	// order to compare them
        q.push(node1->left);
        q.push(node2->right);
        q.push(node1->right);
        q.push(node2->left);
    }
    return true;
}
