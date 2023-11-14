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

    void solve(TreeNode * root, int l, int & ans, int & prevLvl){
        if(root == nullptr) return;
        if(root->left == NULL && root->right == NULL){
            if(l > prevLvl){
                ans = root->val;
                prevLvl = l;
            }
            return;
        }

        prevLvl = max(prevLvl, l);

        if(root->left != nullptr){
            solve(root->left,l+1,ans,prevLvl);
        }
        if(root->right != nullptr){
            solve(root->right,l+1,ans,prevLvl);
        }
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0, prevlvl = -1;
        solve(root,0,ans, prevlvl);
        return ans;
    }
};