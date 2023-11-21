class Solution {


    void dfs(int row,int col,vector<vector<int>>& vis, vector<vector<char>>& grid,int n,int m){
        if(row<0 || col<0 || row>=n || col>=m){
            return;
        }
        if(grid[row][col]=='0' || vis[row][col]==1){
            return;
        }

        vis[row][col]=1;
        dfs(row,col+1,vis,grid,n,m);
        dfs(row,col-1,vis,grid,n,m);
        dfs(row-1,col,vis,grid,n,m);
        dfs(row+1,col,vis,grid,n,m);
        
        

        
    }

    void bfs(int row, int col, vector<vector<int>> & vis, vector<vector<char>> grid,int n, int m){
        vis[row][col] = 1;
        queue<pair<int,int>> q1;
        q1.push({row,col});
        
        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};

        while(!q1.empty()){
            int row = q1.front().first;
            int col = q1.front().second;
            q1.pop();
            
            for(int i = 0; i < 4;i++){
                int nRow = row + delR[i];
                int nCol = col + delC[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]=='1'){
                                vis[nRow][nCol]=1;
                                q1.push({nRow,nCol});
                            }

            }

        }

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,vis,grid,n,m);
                    
                }
            }
        }

        return cnt;
    }
};