class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int mini = -1, n = nums.size();

        for(int i = n-2;i >= 0;i--){
            if(nums[i] < nums[i+1]){
                mini = i;
                break;
            }
        }

        if(mini == -1) {
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i = n-1;i >mini ;i--){
            if(nums[i] > nums[mini]){
                swap(nums[i],nums[mini]);
                break;
            }
        }

        reverse(nums.begin() + mini + 1,nums.end());

        return;
    }
};