class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = 0;
        
        for(int k = 2;k < n;k++){
            int i = 0, j = k-1;

            while(i < j){
                int sum = nums[i] + nums[j];
                if(sum > nums[k]){
                    ans+=j-i;
                    j--;
                }else{
                    i++;
                }
            }
        }

        return ans;

    }
};