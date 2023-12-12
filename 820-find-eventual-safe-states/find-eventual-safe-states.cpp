class Solution {

    bool dfs(int node, vector<vector<int>> graph, int check[], int vis[], int pathVis[]){

        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 1;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,check,vis,pathVis) == true) {
                    check[node] = 0;
                    return true;
                }
            }else if(pathVis[it] == 1){ 
                check[node] = 0;
                return true;
            };
        }

        check[node] = 1;

        pathVis[node] = 0;

        return false;

    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // For DFS
        
        // int V = graph.size();

        // vector<int> safeNodes;
        // int check[V];
        // int pathVis[V];
        // int vis[V];

        // for(int i = 0; i < V;i++){
        //     check[i] = 0;
        //     pathVis[i] = 0;
        //     vis[i] = 0;
        // }

        // for(int i = 0; i < V;i++){
        //     if(!vis[i]){
        //         dfs(i, graph, check, vis, pathVis);
        //     }
        // }

        // for(int i = 0;i < V;i++){
        //     if(check[i] == 1){ 
        //         safeNodes.push_back(i);
        //     };
        // }

        // return safeNodes;

        int V = graph.size();
        vector<int> inDeg(V,0);

        vector<int> rev[V];

        for(int i = 0;i < V;i++){
            for(auto it : graph[i]){
                rev[it].push_back(i);
                inDeg[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for(int i = 0;i < V;i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int f = q.front();
            q.pop();
            ans.push_back(f);

            for(auto it : rev[f]){
                inDeg[it]--;
                if(inDeg[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(ans.begin(),ans.end());

        return ans;

    }
};