class Solution {
    bool check(vector<int> arr, int len, int target){
        if(!(arr[0] <= target) || !(arr[len-1] >= target)) return false;

        int low = 0, high = len-1;

        while(low <= high){
            int mid = (low + high)/2;
            cout << mid<< endl;
            if(arr[mid] == target){
                return true;
            }else if(arr[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }

        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        for(int i = 0; i < n;i++){
            if(check(matrix[i],m,target)){
                return true;
            }
        }

        return false;

    }
};