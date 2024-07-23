class Solution {
    int dp[72][5000];
    int solve(int row,int n, int m, int sum, int target, vector<vector<int>>& mat){
        if(row == m)
        {
            return abs(sum - target);
        }
        
		// Check if already calculated
        if(dp[row][sum] != -1) return dp[row][sum];
        
        int minDiff = INT_MAX;
        for(int i=0; i<n; i++)
        {
            minDiff = min(minDiff, solve( row+1,n, m, sum+mat[row][i], target, mat));
        }
        return dp[row][sum] = minDiff;
    }
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp, -1, sizeof(dp));
        return solve( 0,mat[0].size(),mat.size(),0, target,mat);;
    }
};