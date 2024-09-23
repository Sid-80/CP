class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>> adjList;

        for(auto it : roads){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        int ans = 0;

        for(int i = 0;i < n;i++){
            int cnt = 0;
            
            for(int j = i+1; j < n;j++){
                for(auto it : adjList[i]){
                    if(it != i && it != j){ 
                        cnt+=1;
                    }else if(it == j){
                        cnt+=1;
                    }
                }

                for(auto it : adjList[j]){
                    if(it != i && it != j){ 
                        cnt+=1;
                    }
                }
                ans = max(ans, cnt);
                cnt = 0;
            }


        }
        
        return ans;
    }
};