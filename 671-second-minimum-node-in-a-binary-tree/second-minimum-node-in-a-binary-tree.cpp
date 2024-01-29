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
    void dfs(TreeNode* root,vector<int> & mins){
        if(root == NULL){
            return;
        }

        mins.push_back(root->val);
        dfs(root->left,mins);
        dfs(root->right,mins);

    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> mins;

        dfs(root,mins);

        sort(mins.begin(),mins.end());

        if(mins.size() > 1){
            int min = mins[0];
            for(auto it : mins){
                if(it != min) return it;
            }

        }

        return -1;
    }
};