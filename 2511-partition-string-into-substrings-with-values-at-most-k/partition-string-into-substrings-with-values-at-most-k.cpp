class Solution {
public:
    int minimumPartition(string s, int k) {
        
        int n = s.size();

        vector<int> dp(n + 1, 1e9);

        dp[0] = 0;


        for (int i = 1; i <= n; i++) {
            long long val = 0, mul = 1;
            for (int j = i; j > 0; j--) {
                val += (s[j-1] - '0') * mul;
                if (val > k) break;
                mul *= 10;
                dp[i] = min(dp[i], dp[j-1] + 1);
            }
        }

        return (dp[n] == 1e9) ? -1 : dp[n];
    }
};