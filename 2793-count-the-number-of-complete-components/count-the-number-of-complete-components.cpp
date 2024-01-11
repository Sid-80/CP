class DisjointSet{
public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);

        for(int i = 0;i < n;i++){
            parent[i] = i;
            size[i] = 0;
        }
    }

    int findUparent(int node){
        if(parent[node] == node) return node;

        return parent[node] = findUparent(parent[node]);
    }

    void UnionBySize(int u, int v){

        int up_u = findUparent(u);
        int up_v = findUparent(v);

        if(up_u == up_v) return;
        else if(size[up_u] < size[up_v]){
            parent[up_u] = up_v;
            size[up_v] += up_u;
        }else{
            parent[up_v] = up_u;
            size[up_u] += up_v;
        }
    }
};

class Solution {
public:
    vector<int> group; // group[i] >= 0 means it belongs to another; otherwise i is the group leader and abs(group[i]) is the number of members within the group
    vector<int> count; // number of edges in group i
    
    int Parent(int i) {
        return group[i]<0?i:group[i]=Parent(group[i]);
    }
    void Union(int i, int j) {
        i = Parent(i);
        j = Parent(j);
        if( i != j) {
            // union groups
            group[i] += group[j];
            // accumulate edges
            count[i] += count[j];
            group[j] = i;
            
        } 
        // increment the number of edge after adding a pair
        count[i]++;
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        group.resize(n, -1);
        count.resize(n, 0);
        for(vector<int>& edge: edges) {
            int a = edge[0], b = edge[1];
            Union(a, b);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(group[i]<0) {
                // if there are k nodes, there should be k*(k-1)/2 edges to be the complete connected components
                int k = -group[i];
                if(k*(k-1)/2==count[i])
                    ++ans;
            }
        }
        return ans;
    }

};