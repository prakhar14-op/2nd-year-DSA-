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
    void solve(TreeNode* node,int sum,int len,int &maxLen,int &maxSum){
        if(node==NULL){
            if(len>maxLen){
                maxLen=len;
                maxSum=sum;
            }
            else if(len==maxLen){
                maxSum=max(maxSum,sum);
            }
            return;
        }
        sum+=node->val;
        solve(node->left,sum,len+1,maxLen,maxSum);
        solve(node->right,sum,len+1,maxLen,maxSum);
    }
public:
    int sumOfLongRootToLeafPath(TreeNode* root) {
        int maxLen=0;
        int maxSum=0;
        solve(root,0,0,maxLen,maxSum);
        return maxSum;
    }
};