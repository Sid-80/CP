class Solution {
    bool checkExit(int x, int y, int n, int m){
        if(x >= n || y >= m || x < 0 || y < 0){
            return true;
        }
        return false;
    }

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size(), ans = INT_MAX;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        dist[entrance[0]][entrance[1]] = 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{entrance[0],entrance[1]}});
        
        while(!q.empty()){
            int dis = q.front().first;
            int nodeX = q.front().second.first;
            int nodeY = q.front().second.second;
            q.pop();

            int x[] = {0, 1, 0, -1};
            int y[] = {1, 0, -1, 0};
            
            for(int i = 0;i < 4;i++){
                if(
                    checkExit(nodeX + x[i],nodeY + y[i],n,m) && dis != 0
                ){
                    // cout<<dis<<endl;
                    ans = min(ans, dist[nodeX][nodeY]);
                    break;
                }
            }

            for(int i = 0; i < 4; i++){
                int newX = nodeX + x[i], newY = nodeY + y[i];
                if(!checkExit(newX,newY,n,m) && maze[newX][newY] != '+'){
                    if(dis + 1 < dist[newX][newY]){
                        dist[newX][newY] = dis + 1;
                        q.push({dis+1, {newX, newY}});
                    }
                }
            }
        }

        if(ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};