class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> ans;

        ans.push_back({intervals[0][0],intervals[0][1]});

        for(int i = 1;i < n;i++){
            int a = intervals[i][0];
            int b = intervals[i][1];

            if(a <= ans.back()[1]){
                if(b > ans.back()[1]){
                    ans.back()[1] = b;
                }
            }else{
                ans.push_back({a,b});
            }
        }

        return ans;
    }
};