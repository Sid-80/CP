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
    void dfs1(TreeNode* root, unordered_map<int,int> & mp){
        if(root == nullptr) return;
        
        int sum = 0;
        dfs2(root, sum);
        mp[sum]++;

        // cout<<sum<<endl;
        if(root->left){
            dfs1(root->left, mp);
        }
        if(root->right){
            dfs1(root->right, mp);
        }

    }

    void dfs2(TreeNode* root, int & sum){
        if(root->left == nullptr && root->right == nullptr){
            sum += root->val;
            return;
        }
        
        sum += root->val;

        if(root->left){
            dfs2(root->left, sum);
        }
        if(root->right){
            dfs2(root->right, sum);
        }

        return;
    }

    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;

        dfs1(root, mp);
        
        vector<int> ans;

        int maxi = 0;

        for(auto it : mp){
            maxi = max(it.second, maxi);
        }

        for(auto it : mp){
            if(maxi == it.second){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};