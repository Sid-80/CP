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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode *> q1;
        q1.push(root);
        while(!q1.empty()){
            vector<int> nodes;
            int n = q1.size();
            for(int i = 0;i < n ;i++){
                TreeNode * f = q1.front();
                q1.pop();
                nodes.push_back(f->val);
                if(f->left!=nullptr){ 
                    q1.push(f->left);
                }
                if(f->right!=nullptr) q1.push(f->right);
            }
            ans.push_back(nodes);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};