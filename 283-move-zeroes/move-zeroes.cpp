class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0, end = 0;

        int n = nums.size();

        while(end < n){
            if(nums[end] != 0){
                int temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
                start++;
            }
            end++;
        }
        start++;
        while(start < n){
            nums[start] = 0;
            start++;
        }
    }
};