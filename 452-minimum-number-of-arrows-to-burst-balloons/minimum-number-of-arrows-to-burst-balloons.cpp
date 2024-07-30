class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size();

        if(n == 0 || n == 1) return n;

        int ans = 1, prev1 = points[0][0], prev2 = points[0][1];

        for(auto it : points){
            if(it[0] >= prev1 && it[0] <= prev2){
                prev1 = max(prev1, it[0]);
                prev2 = min(prev2,it[1]);
            }else{
                ans++;
                prev1 = it[0];
                prev2 = it[1];
            }
        }
        return ans;

    }
};