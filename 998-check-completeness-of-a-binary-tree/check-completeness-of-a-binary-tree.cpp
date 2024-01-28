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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;

        while(!q.empty()){
            int sz = q.size();
            
            for(int i = 0;i < sz;i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left){
                    if(flag == 1) return false;
                    q.push(front->left);
                }else{
                    flag=1;
                }

                if(front->right){
                    if(flag == 1) return false;
                    q.push(front->right);
                }else{
                    flag=1;
                }
            }
        }

    

        return true;
    }
};