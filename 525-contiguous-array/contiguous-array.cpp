class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;

        mp[0] = -1;

        int sum = 0, ans = -1e9;

        for(int i = 0;i < n;i++){
            sum += (nums[i] == 1) ? 1 : -1;
            if(mp.count(sum)){
                int idx = mp[sum];
                ans = max(ans, i - idx);
            }else{
                mp[sum] = i;
            }
        }

        return ans == -1e9 ? 0 : ans;
    }
};