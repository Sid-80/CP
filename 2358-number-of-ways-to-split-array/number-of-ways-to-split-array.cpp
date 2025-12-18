class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        vector<long long> ps(n);

        ps[0] = nums[0];

        for(int i = 1;i < n;i++){
            ps[i] = ps[i-1] + nums[i];
        }

        int ans = 0;

        for(int i = 0;i < n-1;i++){
            long long curSum = ps[i];
            long rem = ps[n-1] - ps[i];
            if(curSum >= rem){
                ans += 1;
            }
        }

        return ans;
    }
};