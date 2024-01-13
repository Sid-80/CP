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
    int exe(vector<int>&nums)
	{
	    vector<pair<int,int>> v;
	    int n=nums.size();
	    for(int i=0;i<n;i++)
	    {
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    int cnt=0;
	    for(int i=0;i<n;i++)
	    {
	        if(v[i].second==i) continue;
	        else {
	            cnt++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return cnt;
	}

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = 0;
        q.push(root);

        while(!q.empty()){
            int n = q.size();

            vector<int> order(n);

            for(int i = 0;i < n;i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);

                order.push_back(front->val);
            }

            ans+=exe(order);
        }

        return ans;
    }
};