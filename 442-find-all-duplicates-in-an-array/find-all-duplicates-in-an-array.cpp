class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> freq(nums.size() + 1, 0);
        vector<int> arr;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            if (freq[nums[i]] == 2) {
                arr.push_back(nums[i]);
            }
        }

        return arr;
    }
};