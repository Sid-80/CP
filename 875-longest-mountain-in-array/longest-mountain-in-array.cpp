class Solution {
public:
    vector<int> LIS(vector<int> & arr, int n){
        vector<int> dp(n,1);
        
        for(int i = 1;i < n;i++){
            if(arr[i] > arr[i - 1]){
               dp[i] = 1 + dp[i-1];
            }
        }
        return dp;
    }

    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        vector<int> dp1(n, 1); 
        vector<int> dp2(n, 1);
        int ans = 0; // Variable to store the maximum length of a mountain sequence

        // Calculate the length of the increasing subsequence ending at each index
        for (int ind = 1; ind < n; ind++) {
            if (arr[ind] > arr[ind - 1]) {
                // If the element at the current index is greater than the previous element,
                // we can extend the increasing subsequence. Increment dp[ind] by 1.
                dp1[ind] = 1 + dp1[ind - 1];
            }
        }

        for (int ind = n - 2; ind >= 0; ind--) {
            if (arr[ind] > arr[ind + 1]) {
                dp2[ind] = 1 + dp2[ind + 1];
            }
        }

        for(int i = 0;i < n;i++){
            if(dp1[i] > 1 && dp2[i] > 1) ans = max(ans, dp1[i] + dp2[i] - 1 );
        }
        return ans;
    }
};