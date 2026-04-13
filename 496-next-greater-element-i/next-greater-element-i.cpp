class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;

        int n1 = nums1.size();

        vector<int> ans(n1, -1);

        for(int i = 0;i < n1;i++){
            mp[nums1[i]] = i;
        }

        int n2 = nums2.size();

        st.push(nums2[0]);

        for(int i = 1;i < n2;i++){
            while(!st.empty() && st.top() < nums2[i]){
                if(mp.find(st.top()) != mp.end()){
                    ans[mp[st.top()]] = nums2[i];
                }
                st.pop();
            }

            st.push(nums2[i]);
        }

        return ans;
    }
};