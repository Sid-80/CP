class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;

        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<int> ans;
        m[nums[0]]++;
        
        for(int i = 1;i < n;i++){
            m[nums[i]]++;
            if(nums[i] != nums[i-1]){
                if(m[nums[i-1]] > n/3) ans.push_back(nums[i-1]);
            }
        }

        if(m[nums[n-1]] > n/3) ans.push_back(nums[n-1]);

        return ans;
    }
};