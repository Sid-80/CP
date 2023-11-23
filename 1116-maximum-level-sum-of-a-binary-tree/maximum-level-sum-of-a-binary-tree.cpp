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
    int maxLevelSum(TreeNode* root) {
        int maxLvl = 1, maxSum = root->val;
        queue<TreeNode*> q1;
        q1.push(root);
        int lvl = 1;

        while(!q1.empty()){
            int sum = 0;
            int n = q1.size();

            for(int i = 0; i < n;i++){
                TreeNode* front = q1.front();
                q1.pop();

                sum += front->val;

                if(front->left != nullptr){
                    q1.push(front->left);
                }
                if(front->right != nullptr){
                    q1.push(front->right);
                }
                
            }
            lvl++;

            if(sum > maxSum){
                maxSum = sum;
                maxLvl =lvl; 
            }

        }

        return (maxLvl == 1) ? maxLvl : maxLvl - 1;

    }
};