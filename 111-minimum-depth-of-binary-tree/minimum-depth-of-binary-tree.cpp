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

    int solve(TreeNode* root,int ans){
        if(root->right == NULL && root->left == NULL) return ans; 
        
        int left,right;
        if(root->left != nullptr) left = solve(root->left,ans+1);
        if(root->right != nullptr) right = solve(root->right,ans+1);
        
        return left > right ? right : left;

    }
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = solve(root,0);
        return ans+1;
    }
};