class Solution {
    void solve(int n,int k, long int num, vector<int> & ans){
        if(n == 0){
            ans.push_back(num);
            return;
        }

            if((num % 10 - k) >= 0){
                solve(n-1,k,(num*10)+(num%10 - k), ans);
            }
            if((num % 10 + k) < 10 && k != 0) {
                solve(n-1,k,(num*10)+(num%10 + k), ans);
            }
    }

public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;

        long int num = 0;

        for(int i = 1; i <= 9;i++){
            solve(n-1,k,(num * 10) + i,ans);
        }

        return ans;
    }
};