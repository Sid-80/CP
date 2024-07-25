class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        int ans = 0;

        // single char substring
        for (int i = 0; i < n; ++i) {
            palindrome[i][i] = true;
            ans++;
        }

        //2 char substrings
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                palindrome[i][i + 1] = true;
                ans++;
            }
        }
        //more than 2 char substrings
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                if (s[i] == s[i + len - 1] && palindrome[i + 1][i + len - 2]) {
                    palindrome[i][i + len - 1] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
};