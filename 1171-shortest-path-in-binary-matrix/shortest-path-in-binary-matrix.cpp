class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m,-1));

        if(grid[0][0] == 0){
            q.push({0,{0,0}});
        }
        
        while(!q.empty()){
            int nodeDist = q.front().first;
            int nodeX = q.front().second.first;
            int nodeY = q.front().second.second;
            q.pop();

            for(int i = -1;i <= 1;i++){
                for(int j = -1;j <= 1;j++){
                    int newX = nodeX + i;
                    int newY = nodeY + j;
                    int newDist = nodeDist + 1;

                    if(newX < n && newY < m && newX >=0 && newY >=0){
                        if((dist[newX][newY] > newDist || dist[newX][newY] == -1) && grid[newX][newY] != 1){
                            dist[newX][newY] = newDist;
                            q.push({newDist,{newX,newY}});
                        }
                    }
                }
            }
        }

        if(dist[n-1][m-1] != -1 && n != 1 && m!= 1){
            return dist[n-1][m-1] + 1;
        }

        return dist[n-1][m-1];
    }
};