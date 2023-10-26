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
    pair<bool,int> getAns(TreeNode* root){
        if(!root){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        pair<bool,int> l = getAns(root->left);
        pair<bool,int> r = getAns(root->right);

        bool left = l.first;
        bool right = r.first;
        bool diff = abs((l.second - r.second)) <= 1;

        pair<bool,int> ans;
        ans.first = (left && right && diff);
        ans.second = max(l.second,r.second) + 1;
        
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        pair<bool,int> ans = getAns(root);
        return ans.first;
    }
};