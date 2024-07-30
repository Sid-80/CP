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

        vector<vector<double>> dp(n+1, vector<double> (m+1,0));

        // return getAns(n,m,s,t,dp);

        for(int i = 0;i <= n;i++){
            for(int j = 0;j <= m;j++){
                if(j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                if(i == 0){
                    dp[i][j] = 0;
                    continue;
                }

                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }

            }
        }

        return (int)dp[n][m]; 
    }
};