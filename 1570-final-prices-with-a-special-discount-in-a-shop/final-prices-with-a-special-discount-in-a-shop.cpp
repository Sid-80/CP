class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n,0);
        
        for(int i = 0;i < n;i++){
            int dis = 0;
            for(int j = i+1;j < n;j++){
                if(prices[j] <= prices[i]){
                    dis = prices[j];
                    break;
                }
            }
            ans[i] = (prices[i] - dis);
        }

        return ans;
    }
};