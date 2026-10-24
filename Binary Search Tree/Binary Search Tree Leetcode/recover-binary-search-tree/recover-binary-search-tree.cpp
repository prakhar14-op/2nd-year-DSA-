#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    void inorder(TreeNode* root,vector<int>& in){
        if(root==NULL){
            return ;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    void overwriteTree(TreeNode* root, vector<int>& in, int& index) {
        //base case
        if(root == NULL){
            return;
        }
        overwriteTree(root->left, in, index);
        
        root->val = in[index];
        index++;
        
        overwriteTree(root->right, in, index);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        sort(in.begin(), in.end());\
        int index = 0;
        overwriteTree(root, in, index);
     
    }
};