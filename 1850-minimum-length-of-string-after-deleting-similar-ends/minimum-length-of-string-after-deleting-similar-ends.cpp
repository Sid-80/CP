class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();

        int j = n - 1, i = 0;

        while(i < j){
            if(i >= n || j < 0) return 0;
            if(s[i] != s[j]) return j - i + 1;

            if(s[i] == s[j]){
                char tmp = s[i];
                while(tmp == s[i] && i < n-1){
                    i++;
                }
                while(tmp == s[j] && j >= 0){
                    j--;
                    if(i > j) return 0;
                } 
            }
        }

        return (i == j) ? 1 : 0;
    }
};