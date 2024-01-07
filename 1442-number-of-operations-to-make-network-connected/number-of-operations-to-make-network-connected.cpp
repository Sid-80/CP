class DisjointSet{
    public:
    vector<int> parent,size;
    
    DisjointSet(int n){
        
        size.resize(n+1);
        parent.resize(n+1);
        for(int i = 0;i <= n;i++){
            parent[i] = i;
            size[i] = 1;
        }

    }

    int findUparent(int node){

        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUparent(parent[node]);
    }

    void unionBySize(int u, int v){
        int up_u = findUparent(u);
        int up_v = findUparent(v);

        if(up_u == up_v) return;

        if(size[up_u] < size[up_v]){
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }else{
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisjointSet ds(n);
        int cntExtras = 0;

        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            
            if(ds.findUparent(u) == ds.findUparent(v)){
                //it means they are connected
                cntExtras++;
            }else{
                ds.unionBySize(u,v);
            }

        }

        int cntCon = 0;

        for(int i = 0;i < n;i++){
            if(ds.parent[i] == i){
                cntCon++;
            }
        }

        int ans = cntCon-1;
        
        if(cntExtras >= ans){
            return ans;
        }

        return -1;
    }
};