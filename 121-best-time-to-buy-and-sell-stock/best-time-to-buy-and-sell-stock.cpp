class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int ans = -1;

        int mini = prices[0];

        for(int i = 1;i < n;i++){
            ans = max(ans, prices[i] - mini);
            mini = min(mini, prices[i]);
        }

        return ans == -1 ? 0 : ans;
    }
};