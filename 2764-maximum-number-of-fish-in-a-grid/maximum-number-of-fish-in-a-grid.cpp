class Solution {
public:
    int n,m;
    int dfs(vector<vector<int>>& vis, int row, int col, vector<vector<int>>& grid){
        vis[row][col] = 1;

        int ans = grid[row][col];

        if(row + 1 < n && row + 1 >= 0 && grid[row+1][col] != 0 && vis[row + 1][col] == 0){
            ans += dfs(vis, row+1, col, grid);
        }

        if(row - 1 < n && row - 1 >= 0 && grid[row-1][col] != 0 && vis[row - 1][col] == 0){
            ans += dfs(vis, row-1, col, grid);
        }

        if(col + 1 < m && col + 1 >= 0 && grid[row][col + 1] != 0 && vis[row ][col + 1] == 0){
            ans += dfs(vis, row, col + 1, grid);
        }

        if(col - 1 < m && col - 1 >= 0 && grid[row][col - 1] != 0 && vis[row][col - 1] == 0){
            ans += dfs(vis, row, col - 1, grid);
        }

        return ans;

    }

    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));

        int ans = 0;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    ans = max(ans, dfs(vis,i,j, grid));
                }
            }
        }

        return ans;

    }
};