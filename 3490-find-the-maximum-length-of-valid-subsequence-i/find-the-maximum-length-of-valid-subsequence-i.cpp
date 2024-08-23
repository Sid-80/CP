class Solution {
public:
    int solve(int n, vector<int> nums, bool lastEven, vector<vector<int>>& dp) {
        if (nums.size() == n) {
            return 0;
        }

        if (dp[n][lastEven] != -1)
            return dp[n][lastEven];

        int ans = 0;

        // pick
        if ((nums[n] % 2 == 0 && !lastEven) || (nums[n] % 2 != 0 && lastEven)) {
            ans = max(ans, 1 + solve(n + 1, nums, nums[n] % 2 == 0, dp));
        }

        // not pick
        ans = max(ans, solve(n + 1, nums, lastEven, dp));

        return dp[n][lastEven] = ans;
    }

    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int possible = 4;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0)); //n <odd, even>
        // int ans = max( solve(0, nums, true, dp), solve(0, nums, false, dp) );

        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                int p = 0, np = 0;
                if ((nums[i] % 2 == 0 && j == 0) ||
                    (nums[i] % 2 != 0 && j == 1)) {
                    p = 1 + dp[i + 1][nums[i] % 2 == 0];
                }
                // not pick
                np = dp[i + 1][j];

                dp[i][j] = max(p,np);
            }
        }

        int ans = max(dp[0][0], dp[0][1]);

        int allE = 0, allO = 0;
        for (auto it : nums) {
            if (it % 2 == 0) {
                allE += 1;
            } else
                allO += 1;
        }

        ans = max(ans, max(allE, allO));

        return ans;
    }
};