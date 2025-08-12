class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxLen = 0;
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

        unordered_map<int, int> valToIdx;

        for (int curr = 0; curr < arr.size(); curr++) {
            valToIdx[arr[curr]] = curr;

            for (int prev = 0; prev < curr; prev++) {
                int diff = arr[curr] - arr[prev];
                int prevIdx = (valToIdx.find(diff) != valToIdx.end())
                                  ? valToIdx[diff]
                                  : -1;
                if (diff < arr[prev] && prevIdx >= 0) {
                    dp[prev][curr] = dp[prevIdx][prev] + 1;
                } else {
                    dp[prev][curr] = 2;
                }

                maxLen = max(maxLen, dp[prev][curr]);
            }
        }

        return maxLen > 2 ? maxLen : 0;
    }
};