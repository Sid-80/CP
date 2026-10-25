class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        vector<vector<int>> dpm(n + 1, vector<int> (n + 1, 0));


        // for 1 
        for(int i = 0;i < n;i++){
            dp[i][i] = nums[i];
            dpm[i][i] = nums[i];
        }

        for(int len = 2;len <= n;len++){
            for(int i = 0;i <= n-len;i++){
                int j = i + len - 1;
                dp[i][j] = (dp[i][j-1] ^ dp[i+1][j]);
            }
        }

        for(int len = 2;len <= n;len++){
            for(int i = 0;i <= n-len;i++){
                int j = i + len - 1;
                dpm[i][j] = max(dp[i][j], max(dpm[i][j-1], dpm[i+1][j]));
            }
        }


        vector<int> ans(queries.size(), 0);

        for(int i = 0;i < queries.size();i++){
            ans[i] = dpm[queries[i][0]][queries[i][1]];
        }

        return ans;
    }
};