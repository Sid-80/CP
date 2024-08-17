class Solution {
public:
    typedef long long ll;
    int n, m;

    ll helper(vector<vector<int>> &points, int row, int prevCol, vector<vector<ll>> &dp)
    {
        if (row >= n)
        {
            return 0;
        }

        if (dp[row][prevCol] != -1)
        {
            return dp[row][prevCol];
        }

        ll ans = 0;

        for (int col = 0; col < m; col++)
        {
            ll curr = points[row][col] - abs(col - prevCol) + helper(points, row + 1, col, dp);

            ans = max(ans, curr);
        }

        return dp[row][prevCol] = ans;
    }

    long long maxPoints(vector<vector<int>> &points)
    {
        n = points.size();
        m = points[0].size();

        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

        for (int i = 0; i < m; i++)
        {
            dp[0][i] = points[0][i]; 
        }

        for (int i = 1; i < n; i++)
        {
            vector<ll> leftMax(m), rightMax(m);

            leftMax[0] = dp[i - 1][0];
            for (int j = 1; j < m; j++)
            {
                leftMax[j] = max(leftMax[j - 1] - 1, dp[i - 1][j]);
            }

            rightMax[m - 1] = dp[i - 1][m - 1];
            for (int j = m - 2; j >= 0; j--)
            {
                rightMax[j] = max(rightMax[j + 1] - 1, dp[i - 1][j]);
            }

            for (int j = 0; j < m; j++)
            {
                dp[i][j] = points[i][j] + max(leftMax[j], rightMax[j]);
            }
        }

        ll ans = 0;
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, dp[n - 1][j]);
        }

        return ans;
    }
};