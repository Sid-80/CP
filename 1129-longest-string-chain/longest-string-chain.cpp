class Solution {
public:
    bool compare(string &curr, string & prev){
        int n = curr.size(), m = prev.size();
        if( n != m + 1) return false;
        int i = 0, j = 0;

        while(i < n){
            if(j < m && curr[i] == prev[j]){
                i++;
                j++;
            }else i++;
        }
        
        return (i == n && j == m) ? true : false;

    }

    bool static comp(string & s1, string & s2 ){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        int maxi = 1;
        sort(words.begin(),words.end(),comp);

        for(int i = 0;i < n;i++){
            for(int prev = 0; prev < i;prev++){
                if(compare(words[i],words[prev]) && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    cout<<words[i]<<" "<<words[prev]; 
                }
            }
                maxi = max(maxi,dp[i]);
        }

        return maxi;
    }
};