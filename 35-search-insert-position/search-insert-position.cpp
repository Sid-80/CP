class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        auto tmp = lower_bound(nums.begin(), nums.end(), target);

        return (tmp - nums.begin());
    }
};