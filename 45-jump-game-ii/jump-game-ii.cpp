class Solution {

    int solve(int n, vector<int> nums, int i, vector<int>& dp) {
        if (i >= n - 1) {
            return 0;
        }

        if (dp[i] != -1)
            return dp[i];

        int jumps = nums[i], ans = 1e9;

        for (int j = i + 1; j <= i + jumps; j++) {
            ans = min(ans, 1 + solve(n, nums, j, dp));
        }

        return dp[i] = ans;
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.size(), 0);

        for (int i = n-2; i >= 0; --i) {
            int jumps = nums[i], ans = 1e9;

            for (int step = nums[i]; step >= 1; --step) {
                int jumps = 1;
                if (i + step >= nums.size() - 1) {
                    jumps = 1;
                } else {
                    jumps = 1 + dp[i + step];
                }
                ans = min(ans, jumps);
            }

            dp[i] = ans;
        }

        return dp[0];
    }
};