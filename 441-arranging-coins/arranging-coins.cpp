class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1, j = n;

        while(i <= j){
            long long mid = i + (j - i)/2;
            long long cu =  mid * (mid + 1) / 2;
            if (cu == n) return (int) mid;
            if(cu > n){
                j = mid - 1;
            }else{
                i = mid + 1;
            }
        }

        return j; 
    }
};