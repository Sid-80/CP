class Solution {
public:
    int n;
    int solve(int i, vector<int> & arr, int k, vector<int> & dp){
        if(n == i) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = 0 , maxi = INT_MIN;

        for(int j = i;j < i + k && j < n;j++){
            maxi = max(arr[j],maxi);
            ans = max(ans, maxi * (j - i + 1) + solve(j+1,arr,k,dp));
        }

        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        vector<int> dp(n+1,-1);

        return solve(0,arr,k,dp);
    }
};