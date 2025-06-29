class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> mp;
        vector<string> ans;

        string tmp = "";
        int n = s.size();

        for(int i = 0;i < n;i++){
            tmp += s[i];
            if(mp.find(tmp) == mp.end()){
                mp.insert(tmp);
                ans.push_back(tmp);
                tmp = "";
            }
        }

        return ans;
    }
};