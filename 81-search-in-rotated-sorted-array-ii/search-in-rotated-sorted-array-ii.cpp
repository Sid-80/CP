// Edge Case:
// [3,1,2,3,3,3,3]
// If low = 0, mid = 3, high = 7 then it will be hard to find sorted half
// i.e. arr[low] = arr[mid] = arr[high]
// So here we can apply logic as arr[mid] != target, hence, arr[low] != target as well as arr[high] != target
// We can shrink the arr i.e low = low + 1 and high = high + 1
// Algo 
// 1.Identify the sorted half
// 

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int high = nums.size() - 1, low = 0;

        while(low <= high){
            int mid = (high + low)/2;

            if(nums[mid] == target) return true;
            
            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                low = low + 1;
                high = high - 1;
                continue;
            }

            if(nums[mid] >= nums[low]){
                if(nums[mid] >= target && nums[low] <= target){
                    high = mid-1;
                }else{
                    low = mid + 1;
                }
            }else{
                if(nums[mid] <= target && nums[high] >= target){
                    low = mid+1;
                }else{
                    high = mid - 1;
                }
            }

        }

        return false;
    }
};