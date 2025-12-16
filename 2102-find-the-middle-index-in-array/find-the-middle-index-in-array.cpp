class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> ps(n, 0);

        ps[0] = nums[0];

        for(int i = 1;i < n;i++){
            ps[i] = ps[i-1] + nums[i];
        }
        int i = 0;
        while(i < n){
            int left = 0, right = 0;

            if(i == 0){
                left = 0;
            }else {
                left = ps[i-1];
            }

            if(i == n-1){
                right = 0;
            } else {
                right = ps[n-1] - ps[i];
            }
            // cout<<i<<": "<<left<<" "<<right<<endl;
            if(left == right) return i;

            i++;
        }
        
        
        return -1;
    }
};