class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                int maxi = 0;
                for (int k = i; k <= j; k++) {
                    int coins = nums[i-1] * nums[k] * nums[j+1]
                              + dp[i][k-1]     // 0 when k == i
                              + dp[k+1][j];    // 0 when k == j
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};