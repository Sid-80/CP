/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* dfs(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(!original || !cloned) return NULL;

        if(original == target) return cloned;

        TreeNode* a = dfs(original->left,cloned->left,target);
        TreeNode* b = dfs(original->right,cloned->right,target);

        if(a == nullptr && b== nullptr) return nullptr;

        return (!a) ? b : a;
    }

public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(original,cloned,target);
    }
};