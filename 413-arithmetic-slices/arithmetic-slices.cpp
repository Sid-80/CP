class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        if(n<3)  
			return 0;   

        vector<int> dp(n,0);

        int a,b,c;

		int len=0;
        for(int i=2;i<n;i++)
        {
            a = nums[i-2];
            b = nums[i-1];
            c = nums[i];

            if((b-a) == (c-b))
            {
                len++; 
                dp[i] = dp[i-1] + len;
            }
            else
            {
                len = 0;
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};