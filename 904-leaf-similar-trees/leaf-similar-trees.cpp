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

    void getAns(TreeNode* node, vector<int> & r){
        if(node == nullptr) return;

        if(node->right == nullptr && node->left == nullptr){
            r.push_back(node->val);
            return;
        }

        if(node->left != nullptr) getAns(node->left,r);
        if(node->right != nullptr) getAns(node->right,r);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1, r2;

        getAns(root1, r1);
        getAns(root2, r2);

        return r1 == r2;
    }
};