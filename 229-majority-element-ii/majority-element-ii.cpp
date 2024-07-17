class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<int> ans;
        int curr = 1;
        
        for(int i = 1;i < n;i++){
            if(nums[i] != nums[i-1]){
                if(curr > n/3) ans.push_back(nums[i-1]);

                curr = 0;
            }
            curr++;
        }

        if(curr > n/3) ans.push_back(nums[n-1]);

        return ans;
    }
};