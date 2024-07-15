class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int totalZeros = 0, start = 0, end = 0;

        int n = nums.size(),ans = 0;

        for(end = 0;end < n;end++){
            if(nums[end] == 0) totalZeros++;

            
                
            if(totalZeros - k > 0){
                
                while(totalZeros - k > 0){
                    if(nums[start] == 0) totalZeros--;
                    start++;
                }

            }

            ans = max(ans, (end-start+1));

        }

        return ans;
    }
};