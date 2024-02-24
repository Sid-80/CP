class Solution {
public:
    int findMin(vector<int>& nums) {
        int high = nums.size() - 1, low = 0;
        int ans = 1e9;

        while(low <= high){
            int mid = (high+low)/2;

            ans = min(ans,nums[mid]); //[3,1,3]

            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                ans = min(ans,nums[mid]);
                low = low + 1;
                high = high - 1;
                continue;
            }

            if(nums[low] < nums[high]){
                ans = min(ans,nums[low]);
                break;
            }

            if(nums[mid] >= nums[low]){
                ans = min(ans,nums[low]);
                low = mid + 1;
            }else{
                ans = min(ans,nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};