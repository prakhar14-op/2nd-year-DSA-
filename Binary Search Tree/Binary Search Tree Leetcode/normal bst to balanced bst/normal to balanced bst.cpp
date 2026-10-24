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
class solution{
private:
    void inorder(TreeNode* root,vector<int> &in){
        if(root==NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode* construct(int s,int e,vector<int> &in){
        if(s>e){
            return NULL;
        }
        int mid=(s+e)/2;
        TreeNode* root=new TreeNode(in[mid]);
        root->left=construct(s,mid-1,in);
        root->right=construct(mid+1,e,in);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderset;
        inorder(root,inorderset);
        int n=inorderset.size();
        return construct(0,n-1,inorderset);
    }
};