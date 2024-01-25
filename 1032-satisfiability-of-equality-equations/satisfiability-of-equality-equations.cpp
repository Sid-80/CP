class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
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
public:
    bool equationsPossible(vector<string>& equations) {
        
        DisjointSet ds(26);

        for(auto it : equations){
            // if == then we add edge between them
            if(it[1]==it[2]){
                ds.unionBySize(it[0]-'a',it[3]-'a');
            }
        }

        for(auto it : equations){
            if(it[1]!=it[2]){
                // Checking as specified the variables should not be equal
                // But if present then returning false
                if(ds.findUPar(it[0]-'a') == ds.findUPar(it[3]-'a')){
                    return false;
                }
            }
        }

        return true;
    }
};