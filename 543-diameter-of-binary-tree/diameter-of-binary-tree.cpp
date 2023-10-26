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
    pair<int,int> fastDiameter(TreeNode* root){
        if(root == nullptr){
            pair<int,int> p = make_pair<int,int>(0,0);
            return p;
        }
        pair<int,int> left = fastDiameter(root->left);
        pair<int,int> right = fastDiameter(root->right);
        
        int lDia = left.first;
        int rDia = right.first;
        int combine = left.second + right.second ;

        pair<int,int> ans;
        ans.first = max(lDia, max(rDia,combine));
        ans.second = max(left.second, right.second) + 1;
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return fastDiameter(root).first;
    }
};