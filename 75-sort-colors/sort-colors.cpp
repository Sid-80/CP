class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> m;

        for(auto i : nums){
            if(m.count(i) > 0){
                m[i]++;
            }else{
                m[i] = 1;
            }
        }
        int n = nums.size();

        for(int i = 0;i < n;i++){
            if(m[0] != 0){
                nums[i] = 0;
                m[0]--;
            }else if(m[0] == 0 && m[1] != 0){
                nums[i] = 1;
                m[1]--;
            }else if(m[0] == 0 && m[1] == 0 && m[2] != 0){
                nums[i] = 2;
                m[2]--;
            }
        }

    }
};