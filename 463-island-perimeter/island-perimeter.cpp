class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int di[4]={1,-1,0,0};
        const int dj[4]={0,0,1,-1};
        int cnt=0, n=grid.size(), m=grid[0].size();
        queue<pair<int, int>> q;

        bool flag=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]){
                    q.emplace(i, j);// starting cell
                    grid[i][j]=2;// mark as visited
                    flag=1; 
                    break;
                }
            }
            if(flag) break;
        }

        
        while(!q.empty()){
            auto [i, j]=q.front();
         //   cout<<"("<<i<<","<<j<<")"<<grid[i][j]<<endl;
            q.pop();
            for ( int k=0; k<4; k++){
                int r=i+di[k], s=j+dj[k];
                if (r<0 || r>=n || s<0 || s>=m || grid[r][s]==0){ 
                    cnt++; 
                    continue; 
                }
                if (grid[r][s]==1){
                    q.emplace(r, s);
                    grid[r][s]=2;
                }
            }
        }
        return cnt;
    }
};