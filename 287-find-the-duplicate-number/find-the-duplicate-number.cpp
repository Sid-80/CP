class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = 0;
        int n = nums.size();

        for(int i = 0;i < n;i++){
            m[nums[i]]++;
        }

        for(auto i : m){
            if(i.second > 1){
                ans = i.first;
                break;
            }
        }

        return ans;
    }
};