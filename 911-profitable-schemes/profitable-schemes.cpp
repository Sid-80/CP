class Solution {
public:
    int totalGroups = 0;
    int mod=1000000007;
    int solve(int n, int minProfit, vector<int>& group, vector<int>& profit, int curr, int idx, vector<vector<vector<int>>> & dp){
        if(n - group[idx] < 0) return 0;

        if(idx == totalGroups){
            if(curr >= minProfit && n >= 0){
                return 1;
            }
            return 0;
        }

        if(dp[idx][n-group[idx]][curr] != -1) return dp[idx][n-group[idx]][curr];

        // pick
        int l = 0;
        if(n-group[idx] >= 0){
            l = solve(n-group[idx], minProfit, group, profit, curr+profit[idx],idx+1,dp);
        }

        //n p
        int r = solve(n,minProfit,group,profit,curr,idx+1,dp);

        return dp[idx][n-group[idx]][curr] = l + r;
    }
    int profitableSchemes(int N, int mp, vector<int>& groups, vector<int>& profits) {
        vector<vector<vector<int>>>dp(profits.size()+1,vector<vector<int>>(N+1,vector<int>(mp+1,0)));
        for(int i=0;i<=N;i++){
                dp[profits.size()][i][mp]=1;
        }

        for(int ind=profits.size()-1;ind>=0;ind--){
            for(int n=0;n<=N;n++){
                for(int p=mp;p>=0;p--){
                      long ans=dp[ind+1][n][p];
                     if(n>=groups[ind]) ans+=dp[ind+1][n-groups[ind]][min(mp,p+profits[ind])];
                     dp[ind][n][p]= (int)ans%mod;
                }
            }
        }
        return dp[0][N][0];
    }
};