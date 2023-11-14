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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q1;
        q1.push(root);
        
        while(!q1.empty()){
            int n = q1.size(), max = INT_MIN;
            for(int i = 0;i < n; i++){
                TreeNode * ft = q1.front();
                q1.pop();
                if(ft->val > max){
                    max = ft->val;
                }
                if(ft->left != nullptr){
                    q1.push(ft->left);
                }
                if(ft->right != nullptr){
                    q1.push(ft->right);
                }
            }
            ans.push_back(max);
        }

        return ans;
    }
};