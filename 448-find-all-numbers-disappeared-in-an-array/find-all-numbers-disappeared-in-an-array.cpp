class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> freq(nums.size() + 1, 0);
        vector<int> arr;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for(int i = 1;i <= nums.size();i++){
            if(freq[i] == 0){
                arr.push_back(i);
            }
        }

        return arr;
    }
};