class Solution {
public:
    int dp[21][2001];
    int solve(vector<int>& arr, int target, int i, int sum){
        if(i == arr.size())
            return (target == sum) ? 1 : 0;
        
        if(sum < 0) // -ve index offset as, 0 <= sum(nums[i]) <= 1000, so, at max -1 + 2001 = 2000
            if(dp[i][sum + 2001] != -1)
                return dp[i][sum + 2001];

        else if(sum >= 0)
            if(dp[i][sum] != -1)
                return dp[i][sum];
        
        int addIt = solve(arr, target, i + 1, sum + arr[i]);
        int subtractIt = solve(arr, target, i + 1, sum - arr[i]);
 
        return (sum < 0) ?
            dp[i][sum + 2001] = addIt + subtractIt :
            dp[i][sum] = addIt + subtractIt;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, target, 0, 0);
    }
};