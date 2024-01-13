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

    pair<int,int> getAns(TreeNode* root, int & node){
        if(root == NULL){
            return {0,0};
        }

        auto lh = getAns(root->left,node);
        auto rh = getAns(root->right,node);

        int sum = lh.first + rh.first + root->val;
        int total = lh.second + rh.second + 1;

        if(abs(sum/total) == root->val){
            node++;
        }

        return {sum, total};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        getAns(root,ans);
        return ans;
    }
};