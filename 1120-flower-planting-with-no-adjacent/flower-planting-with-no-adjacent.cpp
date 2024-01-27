class Solution {

    bool ispossible(int nbr,int col,vector<int> adj[],vector<int> &color)
    {
        for(auto x:adj[nbr])
        {
            if(color[x-1]==col)return false;
        }
        return true;
    }

    void dfs(int i,vector<int> &color,vector<int> adj[],vector<int> &vis)
    {
        vis[i]=1;
        for(auto x:adj[i])
        {
            if(!vis[x]){
                for(int col=1;col<=4;col++){
                    if(ispossible(x,col,adj,color)){
                        color[x-1]=col;
                    }
                }
                dfs(x,color,adj,vis);
            }
        }

    }

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1];
        for(auto x:paths)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> color(n,-1);
        vector<int> vis(n+1,0);

        for(int i=1;i<=n;i++)
        { 
            if(!vis[i]) 
            {
                color[i-1]=1;
                dfs(i,color,adj,vis);
            }
        }
            
        return color;
    }
};