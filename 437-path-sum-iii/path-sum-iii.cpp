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

    void dfs2(TreeNode* root,int targetSum, long long sum){
        if(root == NULL) return;

        sum+=root->val;

        if(sum == targetSum){
            ans++;
        }

        dfs2(root->left,targetSum,sum);
        dfs2(root->right,targetSum,sum);
        sum-=root->val;

    }

    void dfs1(TreeNode* root, int targetSum){
        if(root == NULL) return;

        
        dfs1(root->left,targetSum);
        dfs1(root->right,targetSum);

        dfs2(root,targetSum,0);

    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        dfs1(root,targetSum);
        return ans;
    }
};