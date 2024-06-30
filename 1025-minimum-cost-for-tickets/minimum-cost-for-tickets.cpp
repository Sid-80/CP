class Solution {
    int dfs(int i, int n, vector<int> &days, vector<int> &costs, vector<int> &dp) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int one = costs[0], seven = costs[1], thirty = costs[2];
        one += dfs(i + 1, n, days, costs, dp);

        int pos1 = lower_bound(days.begin(), days.end(), days[i] + 7) - days.begin();
        seven += dfs(pos1, n, days, costs, dp);

        int pos2 = lower_bound(days.begin(), days.end(), days[i] + 30) - days.begin();
        thirty += dfs(pos2, n, days, costs, dp);

        return dp[i] = min({one, seven, thirty});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return dfs(0, n, days, costs, dp);
    }
};