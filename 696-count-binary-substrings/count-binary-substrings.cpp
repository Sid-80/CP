class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, curr = 1, ans = 0;
        int n = s.length();
        for(int i = 1;i < n;i++){
            if(s[i] != s[i-1]){
                ans += min(prev,curr);
                prev = curr;
                curr = 1;
            }else{
                curr++;
            }
        }

        ans += min(curr,prev);

        return ans;
    }
};