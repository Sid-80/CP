class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n- 1, ans = 1e9;


        while(i <= j){
            int m = (i + j) / 2;
            ans = min(ans, nums[m]);

            if(nums[i] <= nums[m]){
                if(nums[m] <= nums[j]){
                    j = m - 1;
                } else {
                    i = m + 1;
                }
            }else {
                if(nums[m] <= nums[j]){
                    j = m -1;
                } else {
                    i = m + 1;
                }
            }

        }
        return ans;
    }
};