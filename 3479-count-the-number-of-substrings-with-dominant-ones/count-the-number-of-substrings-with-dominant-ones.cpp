class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> zeroCount(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zeroCount[i] = 1;
            }
            if (i > 0) {
                zeroCount[i] += zeroCount[i - 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int zero = zeroCount[j] - (i > 0 ? zeroCount[i - 1] : 0);
                int one = (j - i + 1) - zero;
                if (zero * zero > one) {
                    j += (zero * zero - one - 1);
                } else if (zero * zero < one) {
                    ans++;
                    int extraZero = sqrt(one) - zero;
                    ans += min(extraZero, n - 1 - j);
                    j += extraZero;
                } else {
                    ans++;
                }
            }
        }
        return ans;
    }
};