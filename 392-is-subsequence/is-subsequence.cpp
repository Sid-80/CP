class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0,j = 0;
        int n = s.size(), m = t.size();
        
        if(n == 0) return true;

        while(i < n && j < m){

            if(i+1 == n && s[i] == t[j]){
                return true;
            }

            if(s[i] == t[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }

        return false;

    }
};