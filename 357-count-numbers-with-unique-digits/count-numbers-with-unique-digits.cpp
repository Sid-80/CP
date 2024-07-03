class Solution {
    int solve(int n, vector<int> & dp){
        if(n == 0) return 1;

        if(dp[n] != -1) return dp[n];
        
        int ans = 9, tmp = 9;

        for(int i = 1;i < n;i++){
            ans*=tmp--;
        }

        return dp[n] = ans + solve(n-1,dp);
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+2,-1);
        dp[0] = 1;
        dp[1] = 10;
        return solve(n,dp);
    }
};