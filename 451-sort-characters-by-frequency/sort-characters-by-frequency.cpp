class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        priority_queue<pair<int,char>> maxHeap;
        int n = s.size();

        for(int i = 0;i < n;i++){
            m[s[i]]++;
        }

        for(auto it : m){
            maxHeap.push({it.second,it.first});
        }

        string ans;

        while(!maxHeap.empty()){
            auto it = maxHeap.top();
            maxHeap.pop();

            for(int i = 0;i < it.first;i++){
                ans+=it.second;
            }

        }

        return ans;

    }
};