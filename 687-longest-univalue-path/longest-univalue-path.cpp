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
    int dfs(TreeNode* root, int & ans){
        if(!root) return 0;

        int lpath = dfs(root->left, ans);
        int rpath = dfs(root->right, ans);

        int l = 0, r = 0;

        if(root->left != nullptr && root->val == root->left->val){
            l = lpath + 1;
        }

        if(root->right != nullptr && root->val == root->right->val){
            r = rpath + 1;
        }

        ans = max(ans, l + r);


        // for univariate we should the longest path
        return max(l,r);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        dfs(root,ans);
        return ans;
    }
};