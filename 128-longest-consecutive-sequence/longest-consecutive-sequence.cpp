class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> checked, present;
        int n = nums.size();

        for(auto it : nums){
            present[it]++;
        }

        for(int i = 0;i < n;i++){
            if(present.find(nums[i] - 1) == present.end()){
                checked[nums[i]]++;
            }
        }

        int ans = 0;

        for(auto it : checked){
            int x = it.first + 1, temp = 1;
            while(present.find(x) != present.end()){
                x += 1;
                temp++;
            }
            ans = max(ans, temp);

        }

        return ans;

    }
};