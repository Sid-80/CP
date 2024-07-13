class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        long long sum = 0;
        int ans = 0;

        for(int i = 0;i < n;i++){
            sum += nums[i];

            if(sum == k){
                ans++;
            }


                int rem = sum - k;

                if(mp.find(rem) != mp.end()){
                    ans+=mp[rem].size();
                }

            mp[sum].push_back(i);
        }

        return ans;
    }
};