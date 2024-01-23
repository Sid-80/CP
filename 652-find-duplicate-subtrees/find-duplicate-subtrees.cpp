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

    string dfs(TreeNode* root, unordered_map<string,int> & m,vector<TreeNode*> & ans){
       
        if(root == NULL) return "#";

        string left = dfs(root->left,m,ans);
        string right = dfs(root->right,m,ans);

        string s = left + "," +right + "," + to_string(root->val);

        if(m[s] == 1) ans.push_back(root);

        m[s]++;

        return s;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> m;
        vector<TreeNode*> ans;

        dfs(root,m,ans);

        return ans;
    }
};