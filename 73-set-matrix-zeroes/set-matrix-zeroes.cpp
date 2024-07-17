class Solution {
public:
    void clearZeros(vector<vector<int>>& matrix, int x, int y, int n, int m){
        // Clearing Row
        for(int i = 0; i < m;i++){
            matrix[x][i] = 0;
        }

        // Clearing col
        for(int i = 0; i < n;i++){
            matrix[i][y] = 0;
        }

        return;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        map<pair<int,int>,int> zeros;

        int n = matrix.size(), m = matrix[0].size();

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] == 0){
                    zeros[{i,j}]++;
                }
            }
        }

        for(auto &it : zeros){
            clearZeros(matrix,it.first.first,it.first.second,n,m);
        }

        return;
    }
};