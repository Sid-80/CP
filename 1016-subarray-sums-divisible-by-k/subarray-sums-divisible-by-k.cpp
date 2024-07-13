class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        unordered_map<int,int> mp;

        for(int i = 0;i < n;i++){
            sum += nums[i];

            if(sum % k == 0){
                ans++;
            }

            int rem = sum % k;

            if (rem < 0)
                rem += k;

            if(mp.find(rem) != mp.end()){
                ans += mp[rem];
            }

            mp[rem]++;
        }

        return ans;

    }
};