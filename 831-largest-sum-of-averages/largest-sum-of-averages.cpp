class Solution {
public:
    auto getSum(vector<int> & ps, int start, int end){
        return (double)(ps[end] - ps[start - 1]) / (end - start + 1);
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<double>> dp(n + 1, vector<double> (k + 2, 0));

        vector<int> ps(n + 1, 0);

        for(int i = 1;i <=n;i++){
            ps[i] = ps[i-1] + nums[i-1];
        }

        // for 1
        for(int i = 1; i <= n;i++){
            dp[i][1] = getSum(ps, 1, i);
        }


         for (int g = 2; g <= k; g++) {
            for (int i = g; i <= n; i++) {
                for (int j = g; j <= i; j++) {
                    dp[i][g] = max(dp[i][g], dp[j - 1][g - 1] + getSum(ps, j, i));
                }
            }
        }
        return dp[n][k];
    }
};