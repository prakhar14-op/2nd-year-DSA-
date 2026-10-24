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
    bool isValidBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        int n=in.size();
        //checking inorder is sorted or not 
        for(int i=0;i<n-1;i++){
            if(in[i]>=in[i+1]){
                return false;
            }
        }
        return true;
    }
};

//You cannot declare a system "valid" just because you found one correct piece of data. You must search the entire system for a violation. If you find a violation, you immediately return false