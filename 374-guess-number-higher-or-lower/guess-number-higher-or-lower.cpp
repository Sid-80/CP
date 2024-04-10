/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long f = 1, l = n;
        while(true){
            int m = (f+l)/2;

            if(guess(m) == -1){
                l = m-1;
            }else if(guess(m) == 1){
                f = m + 1;
            }else{
                return m;
            }
        }

        return 1;
    }
};