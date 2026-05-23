class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.size();

        unordered_map<char,int> mp;

        for(int i = 0;i < n;i++){
            mp[s[i]]++;
            if(mp[s[i]] == 2){
                return s[i];
            }
        }

        return 'a';
    }
};