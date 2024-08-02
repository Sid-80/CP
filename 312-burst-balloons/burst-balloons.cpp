class Solution {
public:
    int solve(int i, int j, vector<int> nums, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int cost = INT_MIN;
        for (int k = i; k <= j; k++) {
            int mini = nums[i - 1] * nums[k] * nums[j + 1] +
                       solve(i, k - 1, nums, dp) + solve(k + 1, j, nums, dp);
            cost = max(cost, mini);
        }

        return dp[i][j] = cost;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= n; j++) {
                if (i > j) continue;

                int cost = INT_MIN;
                for (int k = i; k <= j; k++) {
                    int mini = nums[i - 1] * nums[k] * nums[j + 1] +
                               dp[i][k - 1] +
                               dp[k + 1][j];
                    cost = max(cost, mini);
                }
                dp[i][j] = cost;
            }
        }

        return dp[1][n];
    }
};