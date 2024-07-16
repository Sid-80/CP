class Solution {
public:
    int solve(int num, vector<int>&freq, vector<int> & dp){
        if(num <= 0) return 0;

        if(dp[num] != -1) return dp[num];

        // pick
        int l = num*freq[num];
        if(num>1) l += solve(num-2,freq,dp);

        // not pick
        int r = solve(num-1, freq,dp);

        return dp[num] = max(r,l);
    }

    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(nums[i],maxi);
        }

        vector<int>freq(maxi+1,0);
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            freq[num]++;
        }

        vector<int> dp(maxi+1,-1);
        
        return solve(maxi,freq, dp);
    }
};