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

    void solve(int & ans, TreeNode* root, int &k){
        if(root == nullptr) return;
        solve(ans,root->left,k);
        k--;
        if(k == 0){
                ans = root->val;
                return ;
            }
        solve(ans,root->right,k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        solve(ans,root,k);
        return ans;
    }
};