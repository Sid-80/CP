class Solution {

    int findMaxIndex(vector<vector<int>>& mat, int n, int m, int col){
        int maxValue = -1;
        int index = -1;
        for(int i = 0;i < n;i++){
            if(mat[i][col] > maxValue){
                maxValue = mat[i][col];
                index = i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int low = 0, high = m-1;

        while(low <= high){
            int mid = (low + high)/2;

            int maxRowIndex = findMaxIndex(mat,n,m,mid);

            int l = mid - 1 >= 0 ? mat[maxRowIndex][mid-1] : -1;
            int r = mid + 1 < m ? mat[maxRowIndex][mid+1] : -1;

            if(mat[maxRowIndex][mid] > l && mat[maxRowIndex][mid] > r){
                return {maxRowIndex,mid};
            }else if(mat[maxRowIndex][mid] < l){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return {-1,-1};
    }
};