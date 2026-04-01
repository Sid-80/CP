class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size(), i = 3;
        int ans = 0;

        if(s[0] != s[1] && s[1] != s[2] && s[0] != s[2]){
            ans++;
        }

        while(i < n){
            if(s[i] != s[i-1] && s[i-1] != s[i-2] && s[i] != s[i-2]){
                ans++;
            }
            i++;
        }

        return ans;
    }
};