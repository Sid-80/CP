class Solution {
public:
// example: 9,9,0,-9,9,3,3,3,9
    long long countStableSubarrays(vector<int>& capacity) {
        map<pair<long long, long long>, long long > prefixSum; // prefix sum, nums[index] -> freq

        long long sum = 0, n = capacity.size();

        long long ans = 0;

        for(int i = 0;i < n;i++){
            sum += capacity[i];

            if(prefixSum.find({sum - (2 * capacity[i]), capacity[i]}) != prefixSum.end()){
                ans+=prefixSum[{sum - (2 * capacity[i]), capacity[i]}];
            }
            prefixSum[{sum, capacity[i]}]++;
        }

        for(int i=0;i<n-1;i++){
            //subarrays of sz == 2 of the type [0,0] got 
            //overcounted so subtracting them 
            if(capacity[i]==capacity[i+1] && capacity[i+1]==0){
                ans-- ;
            }

        }
        return ans;

    }
};