class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = 0;

        while(low <= high){
            int mid = (low+high)/2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target){
                high = mid - 1;
            }else{
                ans = mid + 1;
                low = mid + 1;
            }

        }

        return ans;
    }
};