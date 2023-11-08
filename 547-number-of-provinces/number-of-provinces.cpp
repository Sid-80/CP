class Solution {


    void dfs(int node, vector<int> adjList[],int vis[]){
        vis[node] = 1;
        for(auto it : adjList[node]){
            if(!vis[it]){
                dfs(it,adjList,vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<int> adjList[n];
        //changed to Adjacency List
        for(int i = 0; i < n;i++){
            for(int j  = 0;j < n;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int vis[n];
        for(int i = 0; i< n;i++)
            vis[i] = 0;
        int cnt = 0; 
        
        for(int i = 0;i < n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjList,vis);
            }
        }
        
        return cnt;
    }
};