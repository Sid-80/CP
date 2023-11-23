class Solution {
public:
    bool isSameAfterReversals(int num) {
         long x = long(num);
        long y= 0; 
        long z = 0;
        while(x > 0){
            y = (y*10) + (x%10);
            x = x/10;
        }
        while(y > 0){
            z = (z*10) + (y%10);
            y = y/10;
        }
        if(z==num) return true;
        return false;

    }
};