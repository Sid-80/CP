class Solution {
    int n = -1, m = -1;

    bool dfs(vector<vector<int>> &grid1, vector<vector<int>> & grid2, bool & flag, int row, int col){
        
        if(row < 0 || col < 0 || row >= n || col >= m || grid2[row][col] == 0) {
            return true;
        }

        if(grid1[row][col] == 0){ 
            flag = false;
        }

        grid2[row][col] = 0;

        dfs(grid1, grid2, flag,row-1, col);
        dfs(grid1, grid2, flag,row, col+1);
        dfs(grid1, grid2, flag,row+1, col);
        dfs(grid1, grid2, flag,row, col-1);

        return flag;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        int ans = 0;

        for(int i = 0; i < n;i++){
            for(int j= 0;j < m;j++){

                if(grid2[i][j] == 1){
                    bool flag = true;
                    if(dfs(grid1,grid2,flag,i,j)){
                        ans++;
                    }
                }

            }
        }

        return ans;
    }
};