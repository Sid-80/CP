class Solution {
public:
    int solve(vector<int>& coins, int amount, int n, vector<vector<int>> & dp){
        if(amount == 0) return 0;
        if(n < 0 || amount < 0) return INT_MAX-1;

        if(dp[n][amount] != -1) return dp[n][amount];

        int p = solve(coins,amount,n-1,dp);
        int np = 1+solve(coins,amount-coins[n],n,dp);
        
        return dp[n][amount] = min(p,np);
    }

    int coinChange(vector<int>& coins, int amount) {
        int TotalCoins = coins.size();

        vector<vector<int>> dp(TotalCoins+1,vector<int>(amount+1,-1));

        int ans = solve(coins, amount, TotalCoins-1,dp);

        return (ans < INT_MAX-1)?ans:-1;
    }
};