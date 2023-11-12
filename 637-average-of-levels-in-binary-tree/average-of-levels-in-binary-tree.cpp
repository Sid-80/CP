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

    void solve(TreeNode* root,vector<double> & ans){
        
    }

public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q1;

        q1.push(root);


        while(!q1.empty()){
            double n = q1.size(), row = 0;
            for(int i = 0;i < n; i++){
                TreeNode* curr = q1.front();
                q1.pop();
                row += curr->val;
                if(curr->left) q1.push(curr->left);
                if(curr->right) q1.push(curr->right);
            }
            ans.push_back(row/n);
        }

        return ans;
    }
};