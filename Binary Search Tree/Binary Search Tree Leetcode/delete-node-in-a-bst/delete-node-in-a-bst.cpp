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
    TreeNode* minval(TreeNode* root) {
        TreeNode* temp = root;
        while (temp && temp->left != nullptr) {
            temp = temp->left;
        }
        return temp;
    }
    TreeNode* deletee(TreeNode* root, int key){
        //base case
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            //0 child
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            //1 child
            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }

            //2 child
            if(root->left!=NULL && root->right!=NULL){
                //option 2 taking min from right
                int mini=minval(root->right)->val;
                root->val=mini;
                root->right=deletee(root->right,mini);
                return root;
            }
        }
        else if(root->val>key){
            root->left=deletee(root->left,key);
            return root;
        }
        else{
            root->right=deletee(root->right,key);
            return root;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deletee(root, key);
    }
};