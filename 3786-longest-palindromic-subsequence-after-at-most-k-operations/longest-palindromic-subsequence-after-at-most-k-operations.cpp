class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();


        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (n + 1, vector<int> (k + 1, 0)));

        // for 1
        for (int i = 0; i < n; i++) {
            for (int op = 0; op <= k; op++) {
                dp[i][i][op] = 1;
            }
        }

        // for 2,....
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                for (int op = 0; op <= k; op++) {
                    if (s[i] == s[j]) {
                        dp[i][j][op] = 2 + (i + 1 <= j - 1 ? dp[i + 1][j - 1][op] : 0);
                    } else {
                        int cost = min(abs(s[i] - s[j]),26-abs(s[i] - s[j]));
                        dp[i][j][op] = max(dp[i + 1][j][op], dp[i][j - 1][op]);
                        if (op >= cost) {
                            dp[i][j][op] = max(dp[i][j][op], 2 + (i + 1 <= j - 1 ? dp[i + 1][j - 1][op - cost] : 0));
                        }
                    }
                }
            }
        }

        return dp[0][n - 1][k];
    }
};