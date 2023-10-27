class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0, k = 0;
        while(i < nums.size()){
            int curr = nums[i];
            int cnt = 0;
            while(i < nums.size() && nums[i] == curr){
                cnt++;
                i++;
            }
            if(cnt > 1){
                nums[k] = curr;
                k++;
                nums[k] = curr;
                k++;
            }else{
                nums[k] = curr;
                k++;
            }
        }
        return k;
    }
};