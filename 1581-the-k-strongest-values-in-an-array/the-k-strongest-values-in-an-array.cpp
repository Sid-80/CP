class Solution {
public:

    // arr[i] is stronger than arr[j] if |arr[i] - m| > |arr[j] - m| where m is the centre of the array.
    // If |arr[i] - m| == |arr[j] - m|, then arr[i] is said to be stronger than arr[j] if arr[i] > arr[j].

    // center = ((n-1)/2)



    vector<int> getStrongest(vector<int>& nums, int k) {
        if(k == 1 && nums.size() == 1) return nums;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0, j = n-1;

        vector<int> ans;

        int m = (n - 1) / 2;
        int center = nums[m];

        while(i < j){
            int ii = abs(nums[i] - center);
            int jj = abs(nums[j] - center);

            if(ii > jj){
                ans.push_back(nums[i]);
                i++;
            } else if(jj > ii){
                ans.push_back(nums[j]);
                j--;
            } else {
                if(nums[i] > nums[j]){
                    ans.push_back(nums[i]);
                    i++;
                }else {
                    ans.push_back(nums[j]);
                    j--;
                }
            }
            if(ans.size() == k) break;
        }

        if(ans.size() != k){
            (ans[n-2] == nums[i]) ? ans.push_back(nums[j]) : ans.push_back(nums[i]);
        }

        return ans;

    }
};