class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        map<int,int> mp;

        for(int i = 0;i < n;i++){
            mp[nums[i]]++;
        }

        auto start = mp.begin();
        int ans = 0;
        int prev = start->first;
        bool isStart = true;
        int currCnt = 0;

        for(auto it : mp){
            if(isStart && prev == it.first){
                isStart = false;
                currCnt = 1;
            } else {
                if(prev + 1 == it.first){
                    currCnt++;
                } else {
                    currCnt = 1;
                }
                prev = it.first;
            }
            ans = max(ans, currCnt);
        }
        
        return ans;

    }
};