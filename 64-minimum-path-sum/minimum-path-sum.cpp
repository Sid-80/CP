class Solution {
public:

    int mini(int m, int n, vector<vector<int>> &arr, vector<vector<int>> &memo){
        if(m==0 && n==0){
            return arr[0][0];
        }
        if(m<0 || n<0) return 1e9;

        if(memo[m][n]!= -1) return memo[m][n];

        int up = arr[m][n] + mini( m-1, n,arr, memo);
        int left = arr[m][n] + mini(m, n-1, arr, memo);
        memo[m][n] = min(up,  left);
        return memo[m][n];
    }
  
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>( n, -1));
        return mini(m-1, n-1, grid, memo);
    }
};