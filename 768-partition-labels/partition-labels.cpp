class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        vector<int> ans;
        int n1 = s.size();

        for(int i = 0;i < n1;i++){
            m[s[i]] = i;
        }

        int end = 0,start = 0;

        for(int i = 0;i < n1;i++){
            end = max(end,m[s[i]]);

            if(i == end){
                ans.push_back(i-start+1);
                start = i + 1;
            }

        }

        return ans;
    }
};