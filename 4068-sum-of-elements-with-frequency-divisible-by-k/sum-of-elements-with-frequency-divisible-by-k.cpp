class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum = 0;

        for(auto it : nums){
            m[it]++;
        }

        for(auto it: m){
            int first = it.first;
            int sec = it.second;

            if(sec % k == 0){
                sum += (first * sec);
            }

        }

        return sum;
    }
};