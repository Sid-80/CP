class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));

        vector<vector<int>> dist(n,vector<int> (m,0));

        queue<pair<pair<int,int>,int>> q1;

        for(int i = 0; i < n;i++){
            for(int j = 0;j < m;j++){
                if(mat[i][j] == 0){
                    q1.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q1.empty()){
            
                int Dist = q1.front().second;
                int row = q1.front().first.first;
                int col = q1.front().first.second;
                q1.pop();
            
                dist[row][col] = Dist;

                if(row + 1 < n && row + 1 >=0 && vis[row+1][col] == 0){
                    q1.push({{row+1,col},Dist+1});
                    vis[row+1][col] = 1;
                }
                if(row - 1 >= 0 && row - 1 < n && vis[row-1][col] == 0){
                    q1.push({{row-1,col},Dist+1});
                    vis[row-1][col] = 1;
                }
                if(col - 1 >= 0 && col - 1 < m  && vis[row][col-1] == 0){
                    q1.push({{row,col-1},Dist+1});
                    vis[row][col-1] = 1;
                }
                if(col + 1 < m && col + 1 >= 0 && vis[row][col+1] == 0){
                    q1.push({{row,col+1},Dist+1});
                    vis[row][col+1] = 1;
                }
          
        }

        return dist;
    }
};