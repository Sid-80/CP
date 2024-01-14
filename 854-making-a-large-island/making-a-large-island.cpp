class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
    bool isValid(int newr, int newc, int n){
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 0) continue;

                int dr[] = {1,0,-1,0};
                int dc[] = {0,1,0,-1};

                for(int k = 0;k < 4;k++){
                    int newr = i + dr[k];
                    int newc = j + dc[k];

                    if(isValid(newr,newc,n) && grid[newr][newc] == 1){
                        int nodeNo = (i*n) + j;
                        int newNo = (newr*n) + newc;
                        ds.unionBySize(nodeNo,newNo);
                    }
                }
            }
        }

        int ans = 0;

        for(int r = 0;r < n;r++){
            for(int c = 0; c < n;c++){
                if(grid[r][c] == 1) continue;

                
                int dr[] = {1,0,-1,0};
                int dc[] = {0,1,0,-1};
                set<int> components;

                for(int k = 0;k < 4;k++){
                    int newr = r + dr[k];
                    int newc = c + dc[k];

                    if(isValid(newr,newc,n)){
                        if(grid[newr][newc] == 1){
                            components.insert(ds.findUPar(newr * n + newc));
                        }
                    }
                }

                int sizeTotal = 0;
                for(auto it : components){
                    sizeTotal+=ds.size[it];
                } 
                ans = max(ans,sizeTotal + 1);
            }
        }

        for(int i = 0;i < n*n;i++){
            ans = max(ans, ds.size[ds.findUPar(i)]);
        }

        return ans ;
    }
};