class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();

        unordered_map<string,int> mp;

        for(int i = 0;i < n;i++){
            mp[words[i]]++;
        }

        struct cmp {
            bool operator()(pair<string,int> a, pair<string,int> b) {
                if(a.second == b.second) return a.first > b.first;
                return a.second < b.second;
            }
        };

        priority_queue< pair<string,int> ,vector<pair<string,int>>, cmp> pq;

        for(auto it=mp.begin();it!=mp.end();++it) pq.push({it->first,it->second});

        vector<string> ans;
        while(k--)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};