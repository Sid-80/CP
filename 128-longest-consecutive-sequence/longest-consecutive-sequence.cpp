class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> freq;

        for(auto it : nums){
            freq[it]++;
        }
        
        auto start = freq.begin();
        int ans = 0;
        int prev = start->first;
        bool isStart = true;
        int currCnt = 0;

        for(auto it : freq){
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