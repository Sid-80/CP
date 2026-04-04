class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        
        if(k == 1){
            return 0;
        }

        int i = 0, j = k-1, ans = 1e9;
        
        for(j = k-1;j < n;j++){
            ans = min(ans, nums[j] - nums[i]);
            i++;
        }

        return ans;
    }
};