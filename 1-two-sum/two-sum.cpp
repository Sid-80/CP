class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int,int> m;

        for(int start = 0; start < n;start++){
            if(m.find(target - nums[start]) != m.end()){
                return {start,m[target - nums[start]]};
            }
            m[nums[start]] = start;
        }

        return {-1,-1};
    }
};