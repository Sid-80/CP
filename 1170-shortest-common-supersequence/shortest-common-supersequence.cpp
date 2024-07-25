class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        vector<vector<int>> dp(n1+1, vector<int> (n2+1));

        for(int i = 0;i < n1+1;i++){
            for(int j = 0;j < n2+1;j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string ans;
        int x = n1, y = n2;

        while(x > 0 && y > 0){
            if(str1[x-1] == str2[y-1]){
                ans+=str1[x-1];
                x = x - 1;
                y = y - 1;
            }else{
                if(dp[x-1][y] == dp[x][y]){
                    ans+=str1[x-1];
                    x-=1;
                }else{
                    ans+=str2[y-1];
                    y-=1;
                }
                
            }
        }

        while(x != 0){
            ans+=str1[x-1];
            x-=1;
        }
        while(y != 0){
            ans+=str2[y-1];
            y-=1;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};