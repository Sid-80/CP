class Solution {
public:
    int mySqrt(int x) {
        long l = 1, h = x;

        while(l <= h){
            long m = (l + h)/2;

            if((m * m) == x){
                return m;
            }else if( (m-1)*(m-1) < x && (m*m) > x ){
                return m - 1;
            }

            if( (m*m) > x ){
                h = m-1;
            }else{
                l = m + 1;
            }
        }
        
        return 0;
    }
};