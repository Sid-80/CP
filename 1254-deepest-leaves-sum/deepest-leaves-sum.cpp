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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while(!q.empty()){

            int sz = q.size(), cnt = 0;

            for(int i = 0;i < sz;i++){
                TreeNode* front = q.front();
                q.pop();
                cnt += front->val;

                if(front->right){
                    q.push(front->right);
                }
                if(front->left){
                    q.push(front->left);
                }
            }
            ans = cnt;
        }

        return ans;
    }
};