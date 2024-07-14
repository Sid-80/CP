class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> m1, m2;

        int n = p.size(), n2 = s.size();

        int start = 0, end = 0;

        for(end = 0;end < n;end++){
            m1[p[end]]++;
            m2[s[end]]++;
        }

        vector<int> ans;

        if(m1 == m2){
            ans.push_back(start);
        }

        while(end < n2){
            m2[s[end]]++;
            m2[s[start]]--;

            if(m2[s[start]] == 0) m2.erase(s[start]);

            if(m1 == m2){
                ans.push_back(start+1 );
            }

            start++;
            end++;
        }

        return ans;
    }
};