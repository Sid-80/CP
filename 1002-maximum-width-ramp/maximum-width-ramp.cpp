class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;

        int ans = 0;

        st.push({n-1, nums[n-1]});

        for(int i = n-2;i >= 0;i--){
            if(st.top().second < nums[i]){
                st.push({i, nums[i]});
            }
        }

        for(int i = 0;i < n;i++){
            int curr = nums[i];

            while(!st.empty() && st.top().second >= curr){
                ans = max(ans, st.top().first - i);
                st.pop();
            }
        }

        return ans;
    }
};