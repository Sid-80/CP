class Solution {
    int solve(int n, vector<int> nums, vector<int> & dp){
        if(n == 0) return nums[n];
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int p = nums[n] + solve(n-2,nums,dp);
        int np = solve(n-1,nums,dp);

        return dp[n] = max(p,np);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];

        vector<int> temp1, temp2;

        for(int i = 0;i < n;i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        vector<int> dp1(temp1.size(),-1);
        vector<int> dp2(temp1.size(),-1);

        return max(solve(temp1.size()-1,temp1,dp1),solve(temp2.size()-1,temp2,dp2));
    }
};