class Solution {
public:
    int solve(int idx, vector<int>& nums, int rem, vector<vector<int>>& dp){
        if(idx < 0) {
            if(rem == 0){
                return 0;
            }
            return -10000;
        }
        
        if(dp[idx][rem] != -1) return dp[idx][rem];

        // pick
        int l = nums[idx] + solve(idx-1, nums, (rem + nums[idx]) % 3, dp);

        // not pick
        int r = solve(idx-1, nums, rem, dp);

        return dp[idx][rem] = max(l,r);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        vector<vector<int>> dp(n, vector<int>(3,-1));
        
        return solve(n-1,nums,0,dp);
    }
};