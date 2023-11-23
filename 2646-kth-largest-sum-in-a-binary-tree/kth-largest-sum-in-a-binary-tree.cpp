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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == nullptr) return -1;

        int lvl = 0;

        vector<long long> v1(1000000,-1);

        queue<TreeNode*> q1;
        q1.push(root);

        while(!q1.empty()){
            int n = q1.size();
            long long sum = 0;
            for(int i = 0;i < n;i++){
                TreeNode* front = q1.front();
                q1.pop();

                sum += front->val;

                if(front->left != nullptr){
                    q1.push(front->left);
                }
                if(front->right != nullptr){
                    q1.push(front->right);
                }
            }
            lvl++;
            v1[lvl] = sum;
        }

        sort(v1.begin(),v1.end());
        reverse(v1.begin(),v1.end());
        return v1[k-1];

    }
};