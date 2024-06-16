class Solution {
    int getOnes(vector<int> arr, int n){

        int low = 0, high = n - 1;
        int ans = n;

        while(low <= high){
            int mid = (low+high)/2;

            if(arr[mid] >= 1){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return n - ans;
    }

public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOnes = -1;
        int index = -1;

        for(int i = 0;i < mat.size();i++){
            sort(mat[i].begin(),mat[i].end());
            int cnt = getOnes(mat[i], mat[i].size());

            cout<<cnt<<endl;
            
            if(cnt > maxOnes){
                maxOnes = cnt;
                index = i;
            } 
        }

        return {index,maxOnes};
    }
};