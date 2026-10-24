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
    TreeNode* solve(vector<int> & preorder,int mini,int maxi, int &i){//index by refrence karna hai pass
        if(i>=preorder.size()){
            return NULL;
        }
        if(preorder[i]<mini || preorder[i]>maxi){
            return NULL;
        }
        //create node if it lies in the range
        TreeNode* root=new TreeNode(preorder[i++]);
        //recursivly making the left part of tree 
        root->left=solve(preorder,mini,root->val,i);
        root->right=solve(preorder,root->val,maxi,i);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;
        return solve(preorder,mini,maxi,i);
    }
};