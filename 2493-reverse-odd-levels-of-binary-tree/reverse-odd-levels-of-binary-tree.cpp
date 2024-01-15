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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        stack<int> s;
        int lvl = -1;

        while(!q.empty()){
            int n = q.size();
            lvl++;
            for(int i = 0;i < n;i++){
                TreeNode* front = q.front();
                if(lvl % 2 != 0){
                    front->val = s.top();
                    s.pop();
                }
                q.pop();

                if(lvl % 2 == 0){
                    if(front->left){
                        s.push(front->left->val);
                        q.push(front->left);
                    }
                    if(front->right){
                        s.push(front->right->val);
                        q.push(front->right);
                    }
                }else{
                     if(front->left){
                        q.push(front->left);
                    }
                    if(front->right){
                        q.push(front->right);
                    }
                }
            }
        }

        return root;
    }
};