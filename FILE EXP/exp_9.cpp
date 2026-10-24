#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// 1. In-order Traversal (Left, Root, Right)
// This traversal visits the nodes in sorted order.
void inOrder(Node* root) {
    // Base case: If the node is NULL, stop.
    if (root == NULL) {
        return;
    }
    // 1. Go Left
    inOrder(root->left);
    // 2. Visit Root (print the data)
    cout << root->data << " ";
    // 3. Go Right
    inOrder(root->right);
}
// 2. Pre-order Traversal (Root, Left, Right)
// This traversal is useful for copying a tree.
void preOrder(Node* root) {
    // Base case: If the node is NULL, stop.
    if (root == NULL) {
        return;
    }
    
    // 1. Visit Root (print the data)
 cout << root->data << " ";
 // 2. Go Left
 preOrder(root->left);
  // 3. Go Right
 preOrder(root->right);
}
// 3. Post-order Traversal (Left, Right, Root)
// This traversal is useful for deleting a tree from memory.
void postOrder(Node* root) {
 // Base case: If the node is NULL, stop.
 if (root == NULL) {
 return;
 }
 
 // 1. Go Left
 postOrder(root->left);
 
 // 2. Go Right
 postOrder(root->right);
 
 // 3. Visit Root (print the data)
 cout << root->data << " ";
}
int main() {
 
 //  1. Build a Binary Tree 
 cout << "Building the sample tree... " << endl;
 Node* root = createNode(1); // The root
 
 root->left = createNode(2);
 root->right = createNode(3);
 
 root->left->left = createNode(4);
 root->left->right = createNode(5);
 
 root->right->left = createNode(6);
 root->right->right = createNode(7);
 
 cout << "Tree created successfully." << endl;
 
 //  2. Perform Traversals
 
 cout << "\n In-order Traversal (Left, Root, Right)" << endl;
 // 
 inOrder(root);
 cout << endl;
 
 cout << "\n Pre-order Traversal (Root, Left, Right) " << endl;
 // 
 preOrder(root);
 cout << endl;
 
 cout << "\n Post-order Traversal (Left, Right, Root) " << endl;
 // 
 postOrder(root);
 cout << endl;
 return 0;
}