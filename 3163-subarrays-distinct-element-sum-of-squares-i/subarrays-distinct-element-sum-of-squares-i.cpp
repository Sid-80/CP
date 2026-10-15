class Solution {
public:
    int sumCounts(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n + 1, 0);

        int ans = 0;


        for(int i = 1;i <= n;i++){
            unordered_map<int,int> mp;

            int j = i - 1;

            int temp = 0;

            while(j >= 0){
                mp[nums[j]]++;
                temp += (mp.size() * mp.size());
                j--;
            }

            ans += temp;
        }

        return ans;
    }
};