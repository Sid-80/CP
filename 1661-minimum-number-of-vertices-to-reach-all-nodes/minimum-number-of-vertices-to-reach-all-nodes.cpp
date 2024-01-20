class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> vis(n,0);

        for(auto it : edges){
            vis[it[1]] = 1;
        }

        for(int i = 0; i < vis.size();i++){
            if(vis[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};