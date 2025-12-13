class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> ps(n, 0);

        ps[0] = nums[0];

        int mini = ps[0];

        for(int i = 1;i < n;i++){
            ps[i] = ps[i-1] + nums[i];
            mini = min(mini, ps[i]);
        }

        if(mini >= 2) mini = 1;
        
        if(mini < 0){
            mini = mini * (-1) + 1;
        }

        if(mini == 0) mini = mini + 1;


        return mini;
    }
};