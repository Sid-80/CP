class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int ans= k;
        for(int i = 0;i < n;i++){
            if(arr[i] <= ans) ans++;
            else break;
        }
        return ans;
    }
};