class Solution {
public:


    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int count = 0, leftIndex = -1, lastValidIndex = -1;
        int n = nums.size();
        for (int i = 0; i <n;i++){
            if (nums[i] > right){
                leftIndex = i;  
            }
            if(nums[i] >= left && nums[i] <= right){
                lastValidIndex = i;
            }
            if(lastValidIndex > leftIndex){
                count += (lastValidIndex - leftIndex);
            }
        }
        return count;

    }
};