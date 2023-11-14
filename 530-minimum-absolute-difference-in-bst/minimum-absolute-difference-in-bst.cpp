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

    void solve(TreeNode* root, int & minDiff, int& preValue){
        if(root == nullptr) return;
        solve(root->left,minDiff,preValue);
        if(preValue != -1){
            minDiff = min(minDiff, root->val - preValue);
        }
        preValue = root->val;
        solve(root->right,minDiff,preValue);

    }

public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int preValue = -1;
        solve(root,minDiff,preValue);
        return minDiff;
    }
};