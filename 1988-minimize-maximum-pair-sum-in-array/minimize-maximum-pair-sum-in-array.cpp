class Solution {
public:
    // 2, 3, 4, 4, 5, 6
    // 1, 1, 1, 2, 4, 4, 5, 5, 5, 5
    int minPairSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int j = n - 1;

        int ans = 0;

        for(int i = 0;i <= (n-1)/2;i++){
            // cout<<nums[i]<<" "<<nums[j]<<endl;
            ans = max(nums[j] + nums[i], ans);
            j--;
        }

        return ans;
    }
};