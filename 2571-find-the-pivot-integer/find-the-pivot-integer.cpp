class Solution {
public:
    int pivotInteger(int n) {
         for(int i = 1; i<=n; i++){
            int lsum = 0 , rsum = 0;
            lsum = (i*(i+1))/2;
            rsum = ((i+n) * (n-i+1))/2;
            if(lsum == rsum)
            return i;
        }
        return -1;
    }
};