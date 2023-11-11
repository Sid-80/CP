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
    void solve(TreeNode* root, int target, vector<vector<int>> & ans, vector<int> & allSum){
        if(root == nullptr){
            return;
        }

        allSum.push_back(root->val);
        
        if(root->left == nullptr && root->right == nullptr && root->val == target ){
            ans.push_back(allSum);
        }


        solve(root->left,target - root->val,ans, allSum);
        solve(root->right,target - root->val,ans, allSum);
        
        allSum.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> allSum;
        solve(root,targetSum,ans,allSum);
        return ans;
    }
};