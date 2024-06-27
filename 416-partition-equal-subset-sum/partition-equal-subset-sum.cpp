class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for(auto it: nums){
            sum+=it;
        }

        if(sum % 2 != 0) return false;

        int n = nums.size();

        vector<vector<bool>> dp(n+1, vector<bool>(sum/2 + 1, false));

        for(int i = 0;i < n + 1;i++){
            for(int j = 0;j < sum/2 + 1;j++){
                if(j == 0 || i == 0){
                    (j == 0) ? dp[i][j]=true : dp[i][j]=false;
                }else if(nums[i-1] <= j){
                    dp[i][j] = (dp[i-1][j-nums[i-1]] ) || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][sum/2];
    }
};