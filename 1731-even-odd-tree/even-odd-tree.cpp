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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1; // 1-> odd and 0->even

        while(!q.empty()){
            int sz = q.size();

            TreeNode* front = q.front();
            q.pop();
            int prev = front->val;

            if((cnt && prev%2 == 0) || (!cnt && prev%2 != 0)){
                return false;
            }
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }

            for(int i = 1;i < sz;i++){
                front = q.front();
                q.pop();

                
                if(cnt){//odd
                    if(front->val%2 == 0 || front->val <= prev){
                        cout<<front->val<<endl;
                        return false;
                    }
                }else{//even
                    cout<<front->val<<endl;
                    

                    if(front->val%2 != 0 || front->val >= prev){
                        return false;
                    }
                }

                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                prev = front->val;
            }

            (cnt) ? cnt = 0 : cnt = 1;
        }

        return true;

    }
};