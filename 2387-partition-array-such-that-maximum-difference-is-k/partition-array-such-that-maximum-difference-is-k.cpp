class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ans = 1, mini = nums[0], maxi = nums[0];

        for(auto it: nums){
            mini = min(mini, it);
            maxi = max(maxi, it);

            if(maxi - mini > k){
                ans++;
                maxi = mini = it;
            }
        }

        return ans;
    }
};