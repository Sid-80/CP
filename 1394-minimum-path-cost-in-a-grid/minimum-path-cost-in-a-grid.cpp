class Solution {
public:
    int f(vector<vector<int>>& grid, vector<vector<int>>& moveCost,int row,int col,vector<vector<int>> &dp){
        int m = grid.size();
        int n = grid[0].size();
        if(row==0){
            return grid[row][col];
        }
        if(dp[row][col]!=-1)return dp[row][col];
        int cost = INT_MAX;
        for(int i=0;i<n;i++){
            int curr = grid[row][col] + moveCost[grid[row-1][i]][col] + f(grid,moveCost,row-1,i,dp);
            cost = min(curr,cost);
        }
        return dp[row][col]=cost;
        
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        int res = INT_MAX;
        for(int i=0;i<n;i++){
            res = min(res,f(grid,moveCost,m-1,i,dp));
        }
        return res;
    }
};