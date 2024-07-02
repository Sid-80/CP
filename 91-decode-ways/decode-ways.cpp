class Solution {
public:
    int solve(string s, int n, vector<int> & dp){
        if(n > s.size()) return 0;
        if(n == s.size()) return 1;
        if(s[n] == '0') return 0;

        if(dp[n] != -1) return dp[n];

        int p = solve(s,n+1,dp);

        int np = 0;
        string tmp = s.substr(n,2);
        if(stoi(tmp) < 27){
            np = solve(s,n+2,dp);
        }

        return dp[n] = p + np;
    }

    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n,-1);

        return solve(s,0,dp);
    }
};