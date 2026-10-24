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
    void inorder(TreeNode* root,vector<int> &in){
        if(root==NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorderval;
        inorder(root,inorderval);
        int n=inorderval.size();
        int ans= inorderval[k-1];
        return ans;
    }
};