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
    void convertBSTintoDLL(TreeNode* root, TreeNode* &head){
        if(root==NULL){
            return;
        }
        convertBSTintoDLL(root->right,head);
        root->right=head;
        if(head!=NULL){
            head->left=root;
        }
        head=root;
        convertBSTintoDLL(root->left,head);
    }

    int countnodes(TreeNode* head){
        int count=0;
        while(head!=NULL){
            count++;
            head=head->right;
        }
        return count;
    }
    TreeNode* mergeDLL(TreeNode* head1, TreeNode* head2){
        TreeNode* head=NULL;
        TreeNode* tail=NULL;
        while(head1!=NULL && head2!=NULL){
            if(head1->val<head2->val){
                if(head==NULL){
                    head=head1;
                    tail=head1;
                    head1=head1->right;
                }
                else{
                    tail->right=head1;
                    head1->left=tail;
                    tail=head1;
                    head1=head1->right;
                }
            }
            else{
                if(head==NULL){
                    head=head2;
                    tail=head2;
                    head2=head2->right;
                }
                else{
                    tail->right=head2;
                    head2->left=tail;
                    tail=head2;
                    head2=head2->right;
                }
            }
        }
        while(head1!=NULL){
            tail->right=head1;
            head1->left=tail;
            tail=head1;
            head1=head1->right;
        }
        while(head2!=NULL){
            tail->right=head2;
            head2->left=tail;
            tail=head2;
            head2=head2->right;
        }
        return head;

    }
    TreeNode* sortedDLLtoBST(TreeNode* &head, int n){
        if(n<=0 || head==NULL){
            return NULL;
        }
        TreeNode* left=sortedDLLtoBST(head,n/2);
        TreeNode* root=head;
        root->left=left;
        head=head->right;
        root->right=sortedDLLtoBST(head,n-n/2-1);
        return root;
    }
};
