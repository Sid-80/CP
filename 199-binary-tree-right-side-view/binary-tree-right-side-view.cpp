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
    void getAns(TreeNode* root, vector<int> &ans, int lvl){
        if(!root) return ;
        
        if(lvl == ans.size()) ans.push_back(root->val);

        getAns(root->right,ans,lvl+1);
        getAns(root->left,ans,lvl+1);

    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        getAns(root,ans,0);
        return ans;
    }
};