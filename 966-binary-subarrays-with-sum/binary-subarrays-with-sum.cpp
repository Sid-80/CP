class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), ans = 0;
        long long sum = 0;
        unordered_map<int,int> mp;

        for(int i = 0;i < n;i++){
            sum += nums[i];

            if(sum == goal) ans++;

            int rem = sum - goal;

            if(mp.find(rem)!=mp.end()){
                ans += mp[rem];
            }

            mp[sum]++;
        }

        return ans;
    }
};