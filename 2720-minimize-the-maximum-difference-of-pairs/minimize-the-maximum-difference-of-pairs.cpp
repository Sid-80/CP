class Solution {
public:

    bool can(vector<int> arr, int p, int diff){
        int n = arr.size(), cnt = 0;

        for(int i = 0;i < n - 1;i++){
            if(abs(arr[i+1] - arr[i]) <= diff){
                cnt++;
                i++;
            }
        }


        return cnt >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        if(n == 1) return 0;

        int l = 0, r = 1e9;
        int ans = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;

            if(can(nums, p, mid)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};