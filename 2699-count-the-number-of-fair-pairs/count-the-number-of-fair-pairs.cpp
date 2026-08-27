class Solution {
public:

    long long count(vector<int> & nums, int x, int n){
        long long ans = 0;

        for(int i = 0, j = n-1;i < j;i++){
            while(i < j && nums[i] + nums[j] > x) j--;
            ans += j-i;
        }

        // cout<<ans<<endl;
        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        return count(nums, upper, n) - count(nums, lower - 1, n);
    }
};