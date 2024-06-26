class Solution
{
    public:
    
    int solve(int W, int wt[], int val[], int n, vector<vector<int>> & dp){
        if(n==0 || W==0) return 0;
        
        if(dp[n][W] != -1) return dp[n][W];
        
        if(wt[n-1] <= W){
            return dp[n][W] = max(val[n-1] + solve(W-wt[n-1], wt,val, n-1, dp), solve(W, wt,val, n-1, dp));
        }else {
            return  solve(W, wt,val, n-1, dp);
        }
        
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1,-1));
        
        return solve(W, wt, val, n, dp);
    }
};
