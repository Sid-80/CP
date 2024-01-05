class Solution {

    int bfs(int n, int m, vector<vector<int>> grid, int x, int y, vector<vector<int>> & vis){
        queue<pair<int,int>> q;
        int cnt = 0;
        vis[x][y] = 1;

        q.push({x,y});

        while(!q.empty()){
            int nodeX = q.front().first;
            int nodeY = q.front().second;
            q.pop();
            cnt++;

            int cox[] = {0,1,0,-1};
            int coy[] = {1,0,-1,0};

            for(int i = 0;i < 4;i++){
                int newX = nodeX + cox[i];
                int newY = nodeY + coy[i];

                if(newX >= 0 && newY >= 0 && newX < n && newY < m ){
                    if(grid[newX][newY] == 1 && vis[newX][newY] == 0){
                        vis[newX][newY] = 1;
                        q.push({newX,newY});
                    }
                }
            } 
        }

        return cnt;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = INT_MIN;
        vector<vector<int>> vis(n, vector<int> (m,0));
        
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    ans = max(ans,bfs(n,m,grid,i,j,vis));
                }
            }
        }

        return (ans == INT_MIN) ? 0 : ans;
    }
};