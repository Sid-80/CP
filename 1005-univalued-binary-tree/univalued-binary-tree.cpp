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

    bool getAns(TreeNode* root, int val){
        if(root == NULL) return true;

        if(root->val != val){
            return false;
        }

        bool l = true, r = true;
        if(root->val == val){
            if(root->left != nullptr) l = getAns(root->left, val);
            if(root->right != nullptr) r = getAns(root->right, val);
        }

        return (l && r);
    }

public:
    bool isUnivalTree(TreeNode* root) {
        return getAns(root,root->val);
    }
};