class Solution {
public:
    int solve(int m, int n, int x, int y, vector<vector<int>> & dp){
        if(x == m-1 && y == n-1) return 1;

        if(x >= m || y >= n) return 0;

        if(dp[x][y] != -1) return dp[x][y];

        // Down
        int d = solve(m,n,x+1,y,dp);

        // Right
        int r = solve(m,n,x,y+1,dp);

        return dp[x][y] = d + r;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));

        return solve(m,n,0,0,dp);
    }
};