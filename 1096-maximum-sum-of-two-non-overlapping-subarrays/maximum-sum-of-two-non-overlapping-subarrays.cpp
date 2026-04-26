class Solution {
public:
    int solve(vector<int>& nums, int f, int s)
    {
              int n=nums.size();
        
        vector<int> dp1(n,0),dp2(n,0);
        int currsum=0;
        for(int i=0;i<n;i++)
        {
                if(i<f)
                {
                        currsum+=nums[i];
                        dp1[i]=currsum;
                }
                else
                {
                        currsum=currsum-nums[i-f]+nums[i];
                        dp1[i]=max(dp1[i-1],currsum);
                }
        }
        currsum=0;
        for(int i=n-1;i>=0;i--)
        {
                if(i+s>n-1)
                {
                        currsum+=nums[i];
                        dp2[i]=currsum;
                }
                else
                {
                        currsum=currsum-nums[i+s]+nums[i];
                        dp2[i]=max(dp2[i+1],currsum);
                }
        }
        int ans=0;
        for(int i=f-1;i<n-s;i++)
        {
                ans=max(ans , dp1[i]+dp2[i+1]);
        }
        return ans;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int f1, int s1) {
        return max(solve(nums, f1, s1), solve(nums, s1, f1));
    }
};