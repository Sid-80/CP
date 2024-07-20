class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==1) return true;
        long long i = 0, end = (int) sqrt(c);

        while(i <= end){      
            if(i*i + end*end > c){
                end--;
            }else if(i*i + end*end < c){
                i++;
            }else{
                return true;
            }
        }

        return false;
    }
};