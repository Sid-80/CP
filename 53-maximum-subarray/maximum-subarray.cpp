class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxi = -1e9, sum = -1e9;

        for(int i = 0;i < n;i++){
                sum = max(nums[i], sum + nums[i]);
                maxi = max(maxi, sum);
        }

        return maxi;
    }
};