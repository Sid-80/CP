class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int n = nums.size();

        for(int i = 0;i < n;i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for(auto it: mp){
			minHeap.push({it.second, it.first});
			if(minHeap.size()>k){minHeap.pop();}
		}

        vector<int> ans;

        while(!minHeap.empty()){
			ans.push_back(minHeap.top().second);
			minHeap.pop();
		}

        return ans;

    }
};