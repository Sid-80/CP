class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m= grid[0].size(), ans = 0;

        vector<vector<int>> vis(n, vector<int> (m,0));
        
        queue<pair<int,int>> q1;


        // Finding the boundary 1's
        for(int i = 0; i < n;i++){
            for(int j = 0;j < m;j++){
                if(i==0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        q1.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        //bfs

        int travRow[] = {-1,0,+1,0}, travCol[] = {0,+1,0,-1};

        while(!q1.empty()){
            int row = q1.front().first;
            int col = q1.front().second;
            q1.pop();

            //Traversing all four directions

            for(int i = 0;i < 4;i++){
                int r = travRow[i] + row;
                int c = travCol[i] + col;

                if(r < n && c < m && r >=0 && c >= 0 && vis[r][c] == 0 && grid[r][c] == 1){
                    q1.push({r,c});
                    vis[r][c] = 1;
                }
            }
        }

        for(int i = 0; i < n;i++){
            for(int j = 0;j < m;j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    ans++;
                }
            }
        }

        return ans;
    }
};