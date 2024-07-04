class Solution {
public:
    int solve(int ind, vector<vector<int>>& pairs, vector<int> & dp){
        if(ind<0)   return 1;

        if(dp[ind] != -1) return dp[ind];

        int pick=0,not_pick=0;
        not_pick = solve(ind-1,pairs,dp);
        for(int i=ind-1;i>=0;i--){
            if(pairs[ind][0]>pairs[i][1])   pick=max(pick,1+solve(i,pairs,dp));
        }
        return dp[ind] = max(pick,not_pick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int sz=pairs.size();
        vector<int> dp(sz,-1);
        return solve(sz-1,pairs,dp);
    }
};