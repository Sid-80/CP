class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> mp1;
        unordered_map<int,pair<int,int>> mp2;

        for(int it = 0;it < nums.size();it++){
            if(mp1.count(nums[it])){
                mp2[nums[it]] = {mp2[nums[it]].first, it};
            } else {
                mp2[nums[it]] = {it, it};
            }
            mp1[nums[it]]+=1;
            // cout<< nums[it]<<" " <<mp2[nums[it]].first << " "<< it<<endl;
        }

        int ans =1e9;
        int maxi = -1e9;

        for(auto it: mp1){
            if(it.second > maxi){
                maxi = it.second;
            }
        }
        for(auto it: mp1){
            if(it.second == maxi){
                // maxi = it.second;
                // cout<<it.first<<" "<< mp2[it.first].second<<" "<< mp2[it.first].first <<endl;
                ans = min(ans, mp2[it.first].second - mp2[it.first].first + 1);
            }
        }

        return ans;
    }
};