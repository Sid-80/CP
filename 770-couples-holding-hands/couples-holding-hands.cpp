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

    bool union_find(int x, int y)
    {
        int px = findUPar(x);
        int py = findUPar(y);
        
        if (px == py)
            return false;
        
        parent[px] = py;
        return true;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        DisjointSet ds(n);

        for (int i = 0; i < row.size(); i += 2)
        {
            ds.unionBySize(row[i], row[i+1]);
        }
        
        int counter = 0;
        for (int i = 0; i < row.size(); i += 2)
        {
            if (ds.union_find(i, i + 1))
                counter++;
        }
        
        return counter;
    }
};