class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        int ans = 0;

        for(auto it : nums){
            if(freq.find(it-k) != freq.end()){
                ans += freq[it-k];
            }
            if(freq.find(it+k) != freq.end()){
                ans += freq[it+k];
            }
            freq[it]++;
        }

        return ans;
    }
};