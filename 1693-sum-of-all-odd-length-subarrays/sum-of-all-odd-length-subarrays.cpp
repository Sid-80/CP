class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> ps(n + 1, 0);

        ps[0] = 0;

        for(int i = 1;i <= n;i++){
            ps[i] = ps[i-1] + arr[i-1];
        }

        int ans = 0;

        for(int i = 1;i <= n;i++){
            int idx = i;
            while(idx > 1){
                ans += (ps[i] - ps[idx-1]);
                idx-=2;
            }
            if(i & 1 == 1){
                ans += ps[i];
            }
        }

        return ans;

    }
};