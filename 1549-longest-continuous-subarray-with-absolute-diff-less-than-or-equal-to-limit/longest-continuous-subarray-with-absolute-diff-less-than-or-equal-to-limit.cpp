class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int start = 0;

        set<int> temp;
        
        int maxDif = 0, ans = 0;
        unordered_map<int,int> numFreq;

        for(int end = 0;end < n;end++){
            temp.insert(nums[end]);
            numFreq[nums[end]]++;
            auto smallest = temp.begin();
            maxDif = max(maxDif, abs(*--temp.end() - *smallest));

            while(maxDif > limit && start < n && start < end){
                numFreq[nums[start]]--;
                if(numFreq[nums[start]] == 0){
                    temp.erase(nums[start]);
                }
                start++;
                temp.insert(nums[end]);
                int largest1 = *--temp.end();
                maxDif =  abs(largest1 - *temp.begin());
            }

            ans = max(ans, end-start+1);
        }

        return ans;
    }
};