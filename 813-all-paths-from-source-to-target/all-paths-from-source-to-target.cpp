class Solution {

    void dfs(
        vector<vector<int>> graph, 
        vector<int> & temp, 
        vector<vector<int>> & ans, 
        int idx
        ){
            temp.push_back(idx);

            if(idx == graph.size() - 1) ans.push_back(temp);
            else {
                for( auto i : graph[idx]){
                    dfs(graph,temp,ans,i);
                }
            }
            
            temp.pop_back(); 
        }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        vector<int> temp;

        dfs(graph, temp, ans, 0);

        return ans;

    }
};