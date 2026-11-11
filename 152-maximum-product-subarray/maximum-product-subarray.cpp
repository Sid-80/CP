class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = -1e9, maxi = 1;
        int n = nums.size();

        for(int i = 0;i < n;i++){
            maxi = maxi * nums[i];
            ans = max(ans, maxi);
            if(maxi == 0) maxi = 1;
        }
        maxi = 1;
        for(int i = n-1;i >= 0;i--){
            maxi = maxi * nums[i];
            ans = max(ans, maxi);
            if(maxi == 0) maxi = 1;
        }

        return ans;
    }
};