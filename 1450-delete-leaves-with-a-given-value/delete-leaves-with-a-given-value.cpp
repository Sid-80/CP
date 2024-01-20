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
    TreeNode* dfs(TreeNode* root, int target){
        if(!root){
            return NULL;
        }

        root->left = dfs(root->left,target);

        root->right = dfs(root->right,target);

        if(root->left == nullptr && root->right == nullptr && root->val == target){
            return NULL;
        }

        return root;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
       TreeNode* ans = dfs(root,target);
       return ans;
    }
};