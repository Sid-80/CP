// Prefix Sum + subarray dp + partition dp

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<double> pref(n+1, 0.0);
        for(int i = 0; i < n; i++){
            pref[i+1] = pref[i] + nums[i];
        }


        vector<vector<double>> dp(n+1, vector<double> (k + 1, 0.0));

        //Base Case: For parti = 1 partition, the score is just the average of the prefix.
        for(int i = 1; i <= n; i++){
            dp[i][1] = pref[i]/i; 
        }

        
        for(int parti = 2; parti <= k; parti++){
            for(int i = parti; i <= n; i++){
                for(int j = parti-1; j < i; j++){
                    double prev_part_avg = (pref[i] - pref[j])/(double)(i-j);
                    dp[i][parti] = max(dp[i][parti], dp[j][parti-1] + prev_part_avg);
                }
            }
        }

        return dp[n][k];

    }
};