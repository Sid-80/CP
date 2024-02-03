class Solution {

    int bfs(vector<vector<int>> adj, int n){
        vector<int> vis(n,-1);
        queue<int> q;
        q.push(n);
        int lvl = -1;
        vis[n] = 1;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            lvl++;
            for(auto it: adj[front]){
                if(vis[it] == -1){
                    vis[it] = 1;
                    q.push(it);
                }else if(vis[it] == 1){
                    return lvl;
                }
            }
        }

        return -1;
    }

public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int ans=INT_MAX;
        vector<vector<int>> adj(n);
        queue<int> q;

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<n;i++){
            vector<int> visited(n,INT_MAX);
            vector<int> parent(n, -1);

            visited[i]=0;

            q.push(i);

            while(!q.empty()){
                int src=q.front();q.pop();

                for(auto nbr:adj[src]){

                    if(visited[nbr]==INT_MAX){
                        visited[nbr]=visited[src]+1;
                        parent[nbr]=src;
                        q.push(nbr);
                    }
                    else{
                        if(parent[src]==nbr ||parent[nbr]==src) continue;

                        ans=min(ans, abs(visited[src]+visited[nbr])+1);
                    }
                }
            }
            
        }

        return ans == INT_MAX ? -1 : ans;
    }
};