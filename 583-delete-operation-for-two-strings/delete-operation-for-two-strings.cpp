class Solution {
public:
    int minDistance(string word1, string word2) {
        int ans = 0;
        int n1 = word1.size(), n2 = word2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1));

        for(int i = 0;i < n1+1;i++){
            for(int j = 0;j < n2+1;j++){
                if(i == 0|| j == 0) dp[i][j] = 0;
                else if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        ans = (n1 - dp[n1][n2]) + (n2-dp[n1][n2]);

        return ans;
    }
};