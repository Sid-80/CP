class Solution {
    void dfs(int row, int col, int color,int ckcolor, vector<vector<int>>& image, vector<vector<int>>& vis, int n, int m){
        if(row < 0 || col < 0 || row >= n || col >= m) return;

        if(image[row][col] != ckcolor || vis[row][col] == 1) return;

        vis[row][col] = 1;
        image[row][col] = color;

        dfs(row + 1,col,color,ckcolor,image,vis,n,m);
        dfs(row - 1,col,color,ckcolor,image,vis,n,m);
        dfs(row,col + 1,color,ckcolor,image,vis,n,m);
        dfs(row,col - 1,color,ckcolor,image,vis,n,m);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));

        dfs(sr,sc,color,image[sr][sc],image,vis,n,m);

        return image;
    }
};