class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> st; // (greatest till i, current_min)
        int mini = nums[0];
        int n = nums.size();

        for(int i = 1;i < n;i++){
            int t = nums[i];

            while(!st.empty() && t >= st.top().first){
                st.pop();
            }

            if(!st.empty() && t > st.top().second){
                return true;
            }

            st.push({t, mini});
            mini = min(mini, t);
        }

        return false;
    }
};