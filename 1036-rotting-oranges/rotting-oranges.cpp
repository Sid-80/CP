class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int t = 0,NoOfOnes=0;

        queue<pair<pair<int,int>,int>> q1;

        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(grid[i][j] == 2){
                    q1.push({{i,j},0});
                    vis[i][j] = 1;
                }else if(grid[i][j] == 1){
                    NoOfOnes++;
                }
            }
        }

        while(!q1.empty()){
            int nodes = q1.size();
            
            for(int i = 0;i < nodes;i++){
                int row = q1.front().first.first;
                int col = q1.front().first.second;
    
                q1.pop();

                if(row + 1 < n && row + 1 >= 0 && grid[row+1][col] == 1 && vis[row+1][col] != 1){
                    q1.push({{row+1,col},t});
                    vis[row+1][col] = 1;
                    NoOfOnes--;
                }
                if(row - 1 < n && row - 1 >= 0 && grid[row-1][col] == 1 && vis[row-1][col] != 1){
                    q1.push({{row-1,col},t});
                    vis[row-1][col] = 1;
                    NoOfOnes--;
                }
                if(col + 1 < m && col + 1 >= 0 && grid[row][col+1] == 1 && vis[row][col+1] != 1){
                    q1.push({{row,col+1},t});
                    vis[row][col+1] = 1;
                    NoOfOnes--;
                }
                if(col - 1 < m && col - 1 >= 0 && grid[row][col-1] == 1 && vis[row][col-1] != 1){
                    q1.push({{row,col-1},t});
                    vis[row][col-1] = 1;
                    NoOfOnes--;
                }
            }
            t++;
        }

        if(NoOfOnes != 0) return -1;

        return (NoOfOnes == 0 && t==0) ? 0 : t-1;

    }
};