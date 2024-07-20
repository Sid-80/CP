class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, k = n-1;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(i = 0;i < n;i++){
            if(i != 0 && nums[i-1] == nums[i]) continue;

            j = i + 1; k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]){
                        j++;
                    }
                    while(j < k && nums[k] == nums[k+1]){
                        k--;
                    }
                }
            }
        }

        return ans;

    }
};