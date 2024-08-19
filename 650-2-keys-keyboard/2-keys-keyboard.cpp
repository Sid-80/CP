class Solution {
private:
    int targetLength;

    int findMinSteps(int currentLength, int clipboardLength, vector<vector<int>> & dp) {
        if (currentLength == targetLength) return 0;
        if (currentLength > targetLength) return INT_MAX / 2;

        if(dp[currentLength][clipboardLength] != -1) return dp[currentLength][clipboardLength];

        int copyAndPaste = 2 + findMinSteps(currentLength * 2, currentLength, dp);
        int pasteOnly = 1 + findMinSteps(currentLength + clipboardLength, clipboardLength, dp);

        return dp[currentLength][clipboardLength] =  min(copyAndPaste, pasteOnly);
    }

public:
    int minSteps(int n) {
        if (n == 1) return 0;
        targetLength = n;
        vector<vector<int>> dp(n+1, vector<int>(n+1, - 1));
        return 1 + findMinSteps(1, 1, dp);
    }
};