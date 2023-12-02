class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size();

        if(nums[end-1] < target){
            return end;
        }

        while(start <= end){
            int i = (start + end) / 2;
        
            if(nums[i] == target){
                return i;
            }else if(nums[i] < target){
                start = i+1;
            }else if(nums[i] > target){
                end = i -1;
            }

        }

        return start;

    }
};