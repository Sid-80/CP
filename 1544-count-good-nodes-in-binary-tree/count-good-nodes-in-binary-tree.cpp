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
    int ans = 0;

    void dfs(TreeNode* root, int maxN){
        if(root == NULL) return;
        
        if(root->val == maxN || root->val > maxN){
            cout<<root->val<<' ';
            ans++;
        }

        maxN = max(maxN,root->val);

        dfs(root->left,maxN);

        dfs(root->right,maxN);

    }

public:
    int goodNodes(TreeNode* root) {
        
        dfs(root,root->val);

        return ans;
    }
};