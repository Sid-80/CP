class Solution {
public:
    int minBitFlips(int x, int y) {
        int ans = 0;
        for(int i = 0;i < 32;i++){
            if((((x >> i) & 1) == 0) && (((y >> i) & 1) != 0) ){
                ans +=1;
            } else if((((x >> i) & 1) != 0) && (((y >> i) & 1) == 0) ){
                ans += 1;
            }
        }

        return ans;
    }
};