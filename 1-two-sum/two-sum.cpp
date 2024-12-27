class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> getNumber;

        for(int i = 0;i < nums.size();i++){
            int numToBeFound = target - nums[i];

            if(getNumber.find(numToBeFound) != getNumber.end()){
                return {i, getNumber[numToBeFound]};
            }

            getNumber[nums[i]] = i;
        }

        return {-1,-1};
    }
};