class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> efforts(n,vector<int>(m,1e9));

        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});

        efforts[0][0] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            int diff = it.first;
            int nodeX = it.second.first;
            int nodeY = it.second.second;
            pq.pop();

            int r[] = {-1,0,1,0};
            int c[] = {0,1,0,-1};

            if(nodeX == n-1 && nodeY == m-1) return diff;

            for(int i = 0;i < 4;i++){
                int newr = nodeX + r[i];
                int newc = nodeY + c[i];

                if(newr >= 0 && newc >=0 && newr < n && newc < m){
                    int newDiff = max(abs(heights[nodeX][nodeY] - heights[newr][newc]), diff);
                    if(newDiff < efforts[newr][newc]){
                        efforts[newr][newc] = newDiff;
                        pq.push({newDiff,{newr,newc}});
                    }
                }
            }

        }

        return 0;

        // TC : E log V ---> Dijikstra

    }
};