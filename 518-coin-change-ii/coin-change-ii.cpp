class Solution {
    public:
    int n;
    int solve(int amount, vector<int>& coins, int idx, vector<vector<int>> & dp){
        if(idx == 0){
            return amount % coins[0] == 0;
        }

        if(dp[idx][amount]!=-1) return dp[idx][amount];

        int take = 0, notTake = 0;

        if(amount >= coins[idx]) take = solve(amount - coins[idx],coins,idx,dp);

        notTake = solve(amount,coins,idx-1,dp);

        return dp[idx][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(amount, coins,n-1,dp);
    }
};