class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 1, r = 1e9;
        int ans = 1e9;

        while(l <= r){
            int cnt = 0;
            int mid = (l+r)/2;

            for(int i = 0;i < n;i++){
                if(nums[i] <= mid){
                    i++;
                    cnt++;
                }
            }

            if(cnt  >= k){
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }

        }

        return ans;


    }
};