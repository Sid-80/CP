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

    void solve(TreeNode* root,int & ans,int &num){
        if(root==nullptr) return;
       if(root->left == nullptr && root->right == nullptr){
            ans += num *10 + root->val;
            cout<<num<<endl;
            return;
        }
        num = (num * 10) + root->val;
        solve(root->left,ans,num);
        
        solve(root->right,ans,num);
        num = num/10;
    }

public:
    int sumNumbers(TreeNode* root) {
        int ans = 0,num = 0;
        solve(root,ans,num);
        return ans;
    }
};