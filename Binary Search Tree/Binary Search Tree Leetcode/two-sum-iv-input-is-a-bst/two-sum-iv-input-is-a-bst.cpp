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
    void inorder(TreeNode* root,vector<int> & in){
        if(root==NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderset;
        inorder(root,inorderset);
        int i=0;
        int j=inorderset.size()-1;
        while(i<j){
            int summ=inorderset[i]+inorderset[j];
            if(summ==k){
                return true;
            }
            else if(k<summ){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};