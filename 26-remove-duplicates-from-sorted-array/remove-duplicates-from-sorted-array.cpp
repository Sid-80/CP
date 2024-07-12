class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j;
        int i = 0;

        for(j = 0; j <n;j++){
            if(nums[j] != nums[i]){
                nums[i+1] = nums[j];
                i++;
            }
        }

        cout<<i<<endl;

        return i+1;
    }
};