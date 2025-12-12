class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<long long> alt;

        alt.push_back(0);

        int n = gain.size();

        int ans = -1e9;

        for(int i = 0; i < n;i++){
            int tmp = gain[i] + alt[i];
            ans = max(ans, tmp);
            alt.push_back(tmp);
        }

        return ans > 0 ? ans : 0;
    }
};