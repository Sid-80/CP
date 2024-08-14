class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> m;
        for(auto it : s){
            m[it]++;
        }

        int Odds = 0;
        int ans = 0;

        for(auto it : m){
            if(it.second % 2 == 0){
                ans += it.second;
            }else{
                if(it.second != 1){
                    ans += it.second - 1;

                }
                Odds = 1;
            }
        }

        return ans + Odds;

    }
};