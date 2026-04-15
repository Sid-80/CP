class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;

        int ans = -1;

        for(int i = n - 1; i >= 0;i--){
            int t = 0;
            // cout<<nums[i]<<endl;
            while(!st.empty() && st.top().first < nums[i]){
                t = max(t+1, st.top().second);
                st.pop();
            }

            ans = max(ans, t);
            st.push({nums[i], t});
        }

        return ans;
    }
};