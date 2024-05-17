class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size();

        if(nums[0] != 0) return 0;
        
        for(int i =1;i<n;i++){
            if(nums[i] != i){
                return i;
            }
        }

        return n;
    }
};