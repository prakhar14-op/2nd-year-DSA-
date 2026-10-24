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
    TreeNode* insert(TreeNode* root,int val){
        if(root==NULL){
            TreeNode* root=new TreeNode(val);
            return root;
        }
        if(root->val>val){
            //left part me jana 
            root->left=insert(root->left,val);
        }
        else{
            //roght oart me jana 
            root->right=insert(root->right,val);
        }
        return root;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insert(root,val);

    }
};