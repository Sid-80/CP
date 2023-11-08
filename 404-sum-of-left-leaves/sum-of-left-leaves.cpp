/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int n = 0;
    void solve(int & ans, TreeNode* root){
        if(root == nullptr) return;

        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr){
            ans += root->left->val;
        }

        solve(ans,root->left);
        solve(ans,root->right);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root!=NULL){
           if(root->left!=NULL && root->left->left==NULL  
           && root->left->right==NULL){
               n +=root->left->val;
           }
            sumOfLeftLeaves(root->left);
            sumOfLeftLeaves(root->right);
       }
        return n;
    }
};