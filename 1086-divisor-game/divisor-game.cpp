class Solution {
public:
    bool func(int num, vector<int>&dp){
        if(num==1) return 0;
        if(dp[num]!=-1) return dp[num];

        bool ans=0;
        for(int i=1; i*i<num; i++){
            if(num%i==0) if(!func(num-i,dp)){
                ans=1;
                break;
            }
        }
        return dp[num]=ans;
    }

    bool divisorGame(int n) {
        vector<int>dp(n+1,-1);
        return func(n,dp);
    }
};