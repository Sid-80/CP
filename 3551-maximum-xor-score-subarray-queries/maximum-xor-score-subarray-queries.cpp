// perform from taking even length array and odd length array u will get a formula
// a1 a2 a3 a4 a5
// suppose we have already calculated a1 a2 a3 a4
// lettts apply given operations
// a1 ^ a2 | a2 ^ a3 | a3 ^ a4 | a4 ^ a5
// a1 ^ a3 | a2 ^ a4 | a3 ^ a5
// a1 ^ a2 ^ a3 ^ a4 | a2 ^ a3 ^ a4 ^ a5

// we have dp[0][3] and dp[1][4] 

class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int> (n+1, 0)); // storing xors
        vector<vector<int>> dpmax(n + 1, vector<int> (n+1, 0)); // max ans till i...j

        for(int i = 0;i < n;i++){
            dp[i][i] = nums[i];
            dpmax[i][i] = nums[i];
        }


        int len = 2;
        while(len <= n){
            int i = 0;
            int j = i + len - 1;

            while(j < n){
                dp[i][j] = dp[i][j-1] ^ dp[i+1][j];
                dpmax[i][j] = max(dpmax[i][j-1], max(dpmax[i+1][j], dp[i][j]));
                i++;
                j++;
            }

            len++;
        }

        int q = queries.size();

        vector<int> ans;

        for(auto it : queries){
            ans.push_back(dpmax[it[0]][it[1]]);
        }

        return ans;
    }
};