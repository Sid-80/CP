class Solution {
    bool possible(vector<int> nums, int threshold, int div){
        int cnt = 0;
        int n = nums.size();

        for(int i = 0;i < n;i++){
            cnt += ceil((double)(nums[i]) / (double)(div));
        }

        return cnt <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = (low + high)/2;
            if(possible(nums,threshold,mid)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }

        }

        return low;
    }
};