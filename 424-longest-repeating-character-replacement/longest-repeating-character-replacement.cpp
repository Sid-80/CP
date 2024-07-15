class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, end = 0;

        unordered_map<char,int> mp;
        int n = s.size();
        int maxi = 0;

        int ans = 0;

        while(end < n){

            mp[s[end]] = 1 + mp[s[end]];
            maxi = max(maxi, mp[s[end]]);
            
            // checking end present or not
            if(end-start+1 - maxi > k){
                mp[s[start]]-= 1;
                start++;
            }else{
                ans = max(ans,end-start+1);
            }
            end++;
        }

        return ans;
    }
};