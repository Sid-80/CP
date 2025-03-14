class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        int ans = 0, n = nums.size();

        for(int i = 0;i < n;i++){
            freq[nums[i]]++;

            if(freq.find(nums[i]-k) != freq.end()){
                ans+=freq[nums[i]-k];
            }
            if(freq.find(nums[i]+k) != freq.end()){
                ans+=freq[nums[i]+k];
            }

        }

        return ans;
    }
};