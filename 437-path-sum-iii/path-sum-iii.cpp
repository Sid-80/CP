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
    int ans = 0;

    int dfs(TreeNode* root,int targetSum, long long sum){
        if(root == NULL) return 0 ;

        sum += root->val;

        return (sum == targetSum) + dfs(root->left,targetSum,sum) + dfs(root->right,targetSum,sum);

    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
    
        return dfs(root,targetSum,0) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    }
};