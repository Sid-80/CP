class Solution {
public:

    int getAns(int i, int j, string s, string t, vector<vector<int>> & dp){
        if(j == 0) return 1;
        if(i == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1]){
            return dp[i][j] = getAns(i-1,j-1,s,t,dp) + getAns(i-1,j,s,t,dp);
        }

        return dp[i][j] = getAns(i-1,j,s,t,dp);
    }

    int numDistinct(string s, string t) {
        int n  = s.size(); 
        int m  = t.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));

        return getAns(n,m,s,t,dp);

        // for(int i = n;i >= 0;i--){
        //     for(int j = m;j >= 0;j--){
        //         if(j == 0) return 1;
        //         if(i == 0) return 0;

        //         if(s[i-1] == t[j-1]){
        //             dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        //         }else{
        //             dp[i][j] = dp[i-1][j];
        //         }

        //     }
        // }

        // return dp[n][m]; 
    }
};