class Solution {
public:
vector<int> dp;
int fun(int idx,vector<int>& arr,int k){
    
    if(dp[idx] != -1)
        return dp[idx];
    
    int m = -1, sum = 0;
    
    for(int i = 0; i < k; i++){
        if(i+idx >= arr.size())
            continue;
        
        m = max(m,arr[i+idx]);
        sum = max(sum, (m*(i+1)) + fun(idx+i+1,arr,k));
    }
    
    return dp[idx] = sum;
}
int maxSumAfterPartitioning(vector<int>& arr, int k) {
    
    dp = vector<int> (arr.size()+1,-1);
    return fun(0,arr,k);
}
};