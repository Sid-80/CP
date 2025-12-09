class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        for(int i = 0;i < 32;i++){
            int cnt = 0;

            for(int k = 0;k < n;k++){
                cnt += (nums[k] >> i) & 1;
            }

            ans += cnt * (n - cnt); // Set bit * not set bit
        }

        return ans;
    }
};