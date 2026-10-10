class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;

        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));


        for(int i = 0; i< n;i++){
            dp[i][i] = 1;
            ans++;
        }

        int i = 0;

        while(i < n-1){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                ans++;
            } else {
                dp[i][i+1] = 0;
            }
            i++;
        }

        int length = 3;

        while(length <= n){
            i = 0;
            while(i < n-length+1){
                int j = i + length - 1;
                
                if(s[i] == s[j] && dp[i+1][j-1] == 1){
                    dp[i][j] = 1;
                    ans++;
                } else {
                    dp[i][j] = 0;
                }
                i++;

            }
            length++;
        }

        return ans;
    }
};