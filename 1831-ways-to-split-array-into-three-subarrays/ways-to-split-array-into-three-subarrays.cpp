class Solution {
public:
    const int mod = 1e9 + 7;

    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<long long> psum(n+1, 0);

        for (int i = 1; i <= n; i++) {
            psum[i] = psum[i-1] + nums[i-1];
        }

        long long ans = 0;

        for (int i = 0; i < n - 2; i++) {
            long long s1 = psum[i+1];

            // Find first j where psum[j+1] >= 2*s1 
            // Condition1: s1 ≤ psum[j+1] - s1


            int L = lower_bound(psum.begin() + i + 2, psum.end() - 1, 2LL * s1) - psum.begin();

            // Find last j where psum[j+1] <= (psum[n] + s1) / 2 
            // Condition2: psum[j+1] - s1 ≤ psum[n] - psum[j+1]

            long long rightLimit = (psum[n] + s1) / 2;
            int R = upper_bound(psum.begin() + i + 2, psum.end() - 1, rightLimit) - psum.begin() - 1;

            if (L <= R) {
                ans = (ans + (R - L + 1)) % mod;
            }
        }

        return ans;
    }
};
