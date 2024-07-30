class Solution {
public:
    int getAns(int i, int j, string s, string t, vector<vector<int>> & dp){
        // empty string base case
        if(i < 0) return j + 1;
        // when the string t is satisfied then we have del remaining;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = getAns(i-1,j-1,s,t,dp);
        }

        // Insert operation - if we insert then the i stay where it is but the j--;
        int a = 1 + getAns(i,j-1,s,t,dp);

        // Delete
        int b = 1 + getAns(i-1,j,s,t,dp);

        //Replace
        int c = 1 + getAns(i-1,j-1,s,t,dp);

        return dp[i][j] = min(min(a,b),c);
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));

        if(word1 == word2) return 0;

        return getAns(n-1,m-1,word1,word2,dp);
    }
};