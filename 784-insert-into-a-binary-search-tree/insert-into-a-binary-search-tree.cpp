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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(root == NULL){
            TreeNode* t = new TreeNode(val);
            return t;
        }

        if(root->val > val && root->left == nullptr){
            TreeNode* t = new TreeNode(val);
            root->left = t;
            return root;
        }else if(root->val < val && root->right == nullptr){
            TreeNode* t = new TreeNode(val);
            root->right = t;
            return root;
        }


        if(root->val > val && root->left != nullptr){
            insertIntoBST(root->left,val);
        }else if(root->val < val && root->right != nullptr){
            insertIntoBST(root->right,val);
        }

        return root;

    }
};