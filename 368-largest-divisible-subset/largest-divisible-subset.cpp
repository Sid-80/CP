class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxi = 1, lastIndex = 0;

        for(int i = 0; i < n;i++){
            hash[i] = i;
            for(int prev = 0;prev < i;prev++){
                if(nums[i] % nums[prev] == 0  && 1 + dp[prev] > dp[i]  ){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        return ans;
    }
};