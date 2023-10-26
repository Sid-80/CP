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
    bool getAns(TreeNode* root,int t, int sum){
        if(!root->left && !root->right){
            if(t == sum+root->val) return true;
            else return false;
        }
        bool right, left;
        if(root->left){
            left = getAns(root->left,t,sum + root->val);
        }
        if(root->right){
            right = getAns(root->right,t,sum + root->val);
        }
        
        return (left || right);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return getAns(root,targetSum,0);
    }
};