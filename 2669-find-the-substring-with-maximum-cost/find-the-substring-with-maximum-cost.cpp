class Solution {
public:
    int n;
    int solve(int i, int j, string s, unordered_map<int,int> m, vector<int> & dp){
        if(i >= n){
            return 0;
        }

        if(dp[i]!= -1) return dp[i];

        //pick
        int l = 0;
        if(j + 1 < n){
            l = m[s[j]] + solve(i, j + 1, s, m,dp);
        }

        //notpick
        int r = solve(i+1,i+1,s,m,dp);

        return dp[i] = max(l,r);
    }

    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<int,int> m;
        for(int i = 0;i < chars.size();i++){
            m[chars[i]] = vals[i];
        }

        int sum=0,maxsum=0;
        int n = s.length();

        for(int i=0;i<n;i++){
            if(m.find(s[i]) == m.end()){
                sum = sum+(s[i]-'a'+1);
            }else{
                sum += m[s[i]];
                if(sum<0)
                sum = 0;
            }
            maxsum = max(maxsum,sum);
        }

        return maxsum;
    }
};