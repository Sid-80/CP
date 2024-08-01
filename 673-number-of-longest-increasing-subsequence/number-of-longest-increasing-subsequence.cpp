class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,1);
        vector<int> cnt(n,1);

        int maxi = 1;


        for(int i = 0;i < n;i++){
            for(int prev = 0; prev < i;prev++){
                if(nums[i] > nums[prev] && dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                    cnt[i] = cnt[prev];
                }else if(nums[i] > nums[prev] && dp[prev] + 1 == dp[i]){
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(dp[i],maxi);
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(maxi == dp[i]) ans += cnt[i];
        }

        return ans;
    }
};