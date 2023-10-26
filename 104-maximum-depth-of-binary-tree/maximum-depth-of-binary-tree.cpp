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
    int getAns(TreeNode* root, int ans){
        if(root->left==nullptr && root->right==nullptr) return ans;
        int right,left;
        if(root->left != nullptr){
            left = getAns(root->left,ans+1);
        }
        if(root->right != nullptr)
            right = getAns(root->right,ans+1);
        return left > right ? left : right;
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(root->right == nullptr && root->left == nullptr)
            return 1;
        int ans = 0;
        ans = getAns(root,ans);
        return ans+1;
    }
};