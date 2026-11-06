class Solution {
public:
    bool checkIsBalanced(unordered_map<char,int>& mp) {
        int t = -1;
        for (auto& it : mp) {
            if (t == -1) t = it.second;
            if (it.second != t) return false;
        }
        return true;
    }

    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            unordered_map<char,int> mp;
            for (int j = i; j >= 1; j--) {
                mp[s[j-1]]++;
                if (checkIsBalanced(mp)) {
                    dp[i] = min(dp[i], dp[j-1] + 1);
                }
            }
        }
        return dp[n];
    }
};