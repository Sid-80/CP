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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return ans;

        queue<TreeNode*> q1;
        q1.push(root);

        bool LeftToRight = true;

        while(!q1.empty()){
            int size = q1.size();
            vector<int> temp(size);
            for(int i = 0;i < size;i++){
                TreeNode* n = q1.front();
                q1.pop();

                int index = LeftToRight ? i : size - i - 1;
                temp[index] = n->val;
                
                if(n->left) q1.push(n->left);
                if(n->right) q1.push(n->right);
                
            }
            LeftToRight ? LeftToRight = false : LeftToRight = true;
            ans.push_back(temp);
        }

        return ans;

    }
};