class Solution {
    int solve(vector<int> cost, int n, vector<int> & dp){
        if(n == 0 || n == 1){
            return cost[n];
        }
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int l = solve(cost, n-1, dp);

        int r = solve(cost, n-2,dp);

        return dp[n] = cost[n] + min(l,r);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(solve(cost, n-1, dp),solve(cost, n-2, dp));
    }
};