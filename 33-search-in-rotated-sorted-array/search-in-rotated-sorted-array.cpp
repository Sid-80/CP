class Solution {
public:
    // 5,,,7,,,0,....4
    // i    m         j
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int i = 0, j = n-1;

        while(i <= j){
            int m = (i + j) / 2;
            int val = nums[m];

            if(val == target) return m;

            if(nums[i] <= val){
                if(nums[i] <= target && target <= val){
                    j = m - 1;
                } else {
                    i = m + 1;
                }
            } else {
                if(val <= target && target <= nums[j]){
                    i = m + 1;
                } else {
                    j = m - 1;
                }
            }

        }
        return -1;
    }
};