class Solution {
    int solve(int ind, int prev, vector<int> nums, vector<vector<int>> dp){
        if(ind == nums.size()) return 0;

        if(dp[ind][prev+1] != -1) return dp[ind][prev+1]; 

        //not take
        int r = solve(ind+1,prev, nums,dp);

        int l;
        if(prev == -1 || nums[ind] > nums[prev]){
            l = 1 + solve(ind+1, ind,nums,dp);
        }

        return dp[ind][prev+1] = max(l,r);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> next(n+1, 0), curr (n+1,0);

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = ind - 1; prev >= -1; prev--) {
                int len = next[prev+1];
                if (prev == -1 || nums[ind] > nums[prev]) {
                    len = std::max(len, 1 + next[ind + 1]);
                }
                curr[prev + 1] = len;
            }
            next = curr;
        }

        return next[0];
    }
};