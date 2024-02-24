class Solution {
public:
    int findMin(vector<int>& nums) {
        int high = nums.size() - 1, low = 0;
        int ans = 1e9;

        while(low <= high){
            int mid = (high+low)/2;

            ans = min(ans,nums[mid]);

            if(nums[low] <= nums[mid]){
                if(nums[mid] <= nums[high]){
                    // e.g - [11,13,15,17]
                    high = mid - 1;
                }else{
                    // e.g - [4,5,6,7,0,1,2]
                    low = mid + 1;
                }
            }else{
                if(nums[mid] <= nums[high]){
                    // e.g - [11,13,15,17]
                    high = mid - 1;
                }else{
                    // e.g - [4,5,6,7,0,1,2]
                    low = mid + 1;
                }
            }
        }

        return ans;
    }
};