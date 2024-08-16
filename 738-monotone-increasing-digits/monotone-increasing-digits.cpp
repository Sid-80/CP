class Solution {
public:
    int monotoneIncreasingDigits(int num) {
        string s = to_string(num);
        int n = s.length(), idx = n;
        for (int i = n - 1; i > 0; i--) {
            if (s[i] < s[i - 1]) {
                idx = i;
                s[i - 1] = s[i - 1] - 1;
            }
        }
        for (int i = idx; i < n; i++) s[i] = '9';
        return stoi(s);

    }
};