class Solution {
public:

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> g;

        g.push_back(1);
        
        for(auto it : nums){
            g.push_back(it);
        }

        g.push_back(1);
        
        vector<vector<int>> dp(n+5, vector<int> (n+5, 0));
 
        for(int i = 1; i <= n;i++){
            dp[i][i] = g[i-1] * g[i] * g[i+1]; 
        }

        // For Every index assume that you are picking the ith index at last

        int len = 2;
        while(len <= n){
            int i = 1;
            int j = i + len - 1;

            while(j <= n){
                int mini = INT_MIN;
                int k = i; // last element decided to destroy

                while(k <= j){

                    int poss = g[i-1] * g[k] * g[j+1] + dp[i][k-1] + dp[k+1][j];
                    mini = max(mini, poss);

                    k++;
                }
                dp[i][j] = mini;
                i++;
                j++;
            }

            len++;
        }



        return dp[1][n ];

    }
};