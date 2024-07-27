class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
                vector<int> indicesOfC;
        int n = s.length();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == c) indicesOfC.push_back(i);
        }
        int m = indicesOfC.size();
        int left = 0;
        int right = 0;
        for (int i = 0; i < n; i++) {
            if (i > indicesOfC[right] && right < m - 1) {
                  left = right; 
                right++;
            }
            if (right == left) {
                ans[i] = abs(indicesOfC[right] - i);
            } else {
                ans[i] = min(abs(indicesOfC[right] - i), abs(indicesOfC[left] - i));
            }
        }
        return ans;
    }
};