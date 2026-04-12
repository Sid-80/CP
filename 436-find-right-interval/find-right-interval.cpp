class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> ans(n);
        map<int,int> mp;

        for(int i = 0;i < n;i++){
            mp[intervals[i][0]] = i;
        }

        for(int i = 0;i < n;i++){
            ans[i] = mp.lower_bound(intervals[i][1]) != mp.end() ? mp.lower_bound(intervals[i][1])->second : -1;
        }

        return ans;
    }
};