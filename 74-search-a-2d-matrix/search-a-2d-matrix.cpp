class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();

        int row = 0;

        for(int i = 0;i < r;i++){
            if(matrix[i][0] <= target && matrix[i][c-1] >= target){
                row = i;
                break;
            }
        }

        int start = 0, end = c - 1;

        while(start <= end){
            int mid = start + (end- start) / 2;

            if(matrix[row][mid] == target){
                return true;
            } else if(matrix[row][mid] > target){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return false;
    }
};